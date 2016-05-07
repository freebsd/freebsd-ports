# $FreeBSD$
#
# Support rubygem packages
#
# Feature:	gem
# Usage:	USES=gem[:noautoplist]
# Valid args:	noautoplist	Don't generate the plist automatically
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_GEM_MK)

_INCLUDE_USES_GEM_MK=        yes

_valid_ARGS=			noautoplist

# Sanity check
.for arg in ${gem_ARGS}
.    if empty(_valid_ARGS:M${arg})
IGNORE= Incorrect 'USES+= gem:${gem_ARGS}' usage: argument [${arg}] is not recognized
.    endif
.endfor

BUILD_DEPENDS+=	${RUBYGEMBIN}:devel/ruby-gems
RUN_DEPENDS+=	${RUBYGEMBIN}:devel/ruby-gems

PKGNAMEPREFIX?=	rubygem-
EXTRACT_SUFX=	.gem
EXTRACT_ONLY=
DIST_SUBDIR=	rubygem

EXTRACT_DEPENDS+=	${RUBYGEMBIN}:devel/ruby-gems
GEMS_BASE_DIR=	lib/ruby/gems/${RUBY_VER}
GEMS_DIR=	${GEMS_BASE_DIR}/gems
DOC_DIR=	${GEMS_BASE_DIR}/doc
CACHE_DIR=	${GEMS_BASE_DIR}/cache
SPEC_DIR=	${GEMS_BASE_DIR}/specifications
EXT_DIR=	${GEMS_BASE_DIR}/extensions
GEM_NAME?=	${PORTNAME}-${PORTVERSION}
GEM_LIB_DIR?=	${GEMS_DIR}/${GEM_NAME}
GEM_DOC_DIR?=	${DOC_DIR}/${GEM_NAME}
GEM_SPEC?=	${SPEC_DIR}/${GEM_NAME}.gemspec
GEM_CACHE?=	${CACHE_DIR}/${GEM_NAME}.gem
GEMSPEC=	${PORTNAME}.gemspec
GEM_ENV+=	RB_USER_INSTALL=yes

.if defined(LANG) && !empty(LANG)
GEM_ENV+=		LANG=${LANG}
.else
GEM_ENV+=		LANG=en_US.UTF-8
.endif

.if defined(LC_ALL) && !empty(LC_ALL)
GEM_ENV+=		LC_ALL=${LC_ALL}
.else
GEM_ENV+=		LC_ALL=en_US.UTF-8
.endif

.if defined(LC_CTYPE) && !empty(LC_CTYPE)
GEM_ENV+=		LC_CTYPE=${LC_CTYPE}
.else
GEM_ENV+=		LC_CTYPE=UTF-8
.endif

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		REV="${RUBY_GEM}" \
		GEMS_BASE_DIR="lib/ruby/gems/${RUBY_VER}" \
		GEMS_DIR="${GEMS_DIR}" \
		DOC_DIR="${DOC_DIR}" \
		CACHE_DIR="${CACHE_DIR}" \
		SPEC_DIR="${SPEC_DIR}" \
		EXT_DIR="${EXT_DIR}" \
		PORT="${PORTNAME}-${PORTVERSION}" \
		GEM_NAME="${GEM_NAME}" \
		GEM_LIB_DIR="${GEM_LIB_DIR}" \
		GEM_DOC_DIR="${GEM_DOC_DIR}" \
		GEM_SPEC="${GEM_SPEC}" \
		GEM_CACHE="${GEM_CACHE}" \
		EXTRACT_SUFX="${EXTRACT_SUFX}"

RUBYGEMBIN=	${LOCALBASE}/bin/gem${RUBY_VER:S/.//}

. if defined(DISTFILES)
GEMFILES=	${DISTFILES:C/:[^:]+$//}
. else
GEMFILES=	${DISTNAME}${EXTRACT_SUFX}
. endif

RUBYGEM_ARGS=-l --no-update-sources --install-dir ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} --ignore-dependencies --bindir=${STAGEDIR}${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
RUBYGEM_ARGS+=	--rdoc --ri
.else
RUBYGEM_ARGS+=	--no-rdoc --no-ri
.endif

.if !target(do-extract)
do-extract:
	@${SETENV} ${GEM_ENV} ${RUBYGEMBIN} unpack --target=${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/${GEMFILES}
	@(cd ${BUILD_WRKSRC}; if ! ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} spec --ruby ${DISTDIR}/${DIST_SUBDIR}/${GEMFILES} > ${GEMSPEC} ; then \
		if [ -n "${BUILD_FAIL_MESSAGE}" ] ; then \
			${ECHO_MSG} "===> Extraction failed unexpectedly."; \
			(${ECHO_CMD} "${BUILD_FAIL_MESSAGE}") | ${FMT} 75 79 ; \
			fi; \
		${FALSE}; \
		fi)
.endif

.if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; if ! ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} build --force ${GEMSPEC} ; then \
		if [ -n "${BUILD_FAIL_MESSAGE}" ] ; then \
			${ECHO_MSG} "===> Compilation failed unexpectedly."; \
			(${ECHO_CMD} "${BUILD_FAIL_MESSAGE}") | ${FMT} 75 79 ; \
			fi; \
		${FALSE}; \
		fi)
.endif

.if !target(do-install)
do-install:
	(cd ${BUILD_WRKSRC}; ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} install ${RUBYGEM_ARGS} ${GEMFILES} -- --build-args ${CONFIGURE_ARGS})
	${RM} -r ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}/build_info/
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -type f -name '*.so' -exec ${STRIP_CMD} {} +
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -type f \( -name mkmf.log -or -name gem_make.out \) -delete
	${RM} -rf ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext \
		${STAGEDIR}${PREFIX}/${CACHE_DIR} 2> /dev/null || ${TRUE}
	${RMDIR} ${STAGEDIR}${PREFIX}/${EXT_DIR} 2> /dev/null || ${TRUE}
.if defined(NOPORTDOCS)
	-@${RMDIR} ${STAGEDIR}${PREFIX}/${DOC_DIR}
.endif
.endif

.if empty(gem_ARGS:Mnoautoplist)
_USES_install+=	820:gem-autoplist
gem-autoplist:
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${DOC_DIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
.endif
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
	@if [ -d ${STAGEDIR}${PREFIX}/${EXT_DIR} ]; then \
		${FIND} -ds ${STAGEDIR}${PREFIX}/${EXT_DIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST} ; \
	fi
.endif

.endif
