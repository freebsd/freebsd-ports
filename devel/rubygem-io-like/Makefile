# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	io-like
PORTVERSION=	0.3.0.20130301
CATEGORIES=	devel rubygems
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	tota@FreeBSD.org
COMMENT=	The interface of IO objects to classes providing a few simple methods

BUILD_DEPENDS=	${RUBYGEMBIN}:${PORTSDIR}/devel/ruby-gems \
		rdoc:${PORTSDIR}/devel/rubygem-rdoc
RUN_DEPENDS=	${RUBYGEMBIN}:${PORTSDIR}/devel/ruby-gems

USE_RUBY=	yes
USE_RAKE=	yes

GEMS_BASE_DIR=	lib/ruby/gems/${RUBY_VER}
GEMS_DIR=	${GEMS_BASE_DIR}/gems
DOC_DIR=	${GEMS_BASE_DIR}/doc
CACHE_DIR=	${GEMS_BASE_DIR}/cache
SPEC_DIR=	${GEMS_BASE_DIR}/specifications
GEM_NAME=	${PORTNAME}-${PORTVERSION:C/(\.[0-9]+)$//}
GEM_LIB_DIR=	${GEMS_DIR}/${GEM_NAME}
GEM_DOC_DIR=	${DOC_DIR}/${GEM_NAME}
GEM_SPEC=	${SPEC_DIR}/${GEM_NAME}.gemspec
GEM_CACHE=	${CACHE_DIR}/${GEM_NAME}.gem

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		REV="${RUBY_GEM}" \
		GEMS_BASE_DIR="lib/ruby/gems/${RUBY_VER}" \
		GEMS_DIR="${GEMS_DIR}" \
		DOC_DIR="${DOC_DIR}" \
		CACHE_DIR="${CACHE_DIR}" \
		SPEC_DIR="${SPEC_DIR}" \
		PORT="${PORTNAME}-${PORTVERSION}" \
		GEM_NAME="${GEM_NAME}" \
		GEM_LIB_DIR="${GEM_LIB_DIR}" \
		GEM_DOC_DIR="${GEM_DOC_DIR}" \
		GEM_SPEC="${GEM_SPEC}" \
		GEM_CACHE="${GEM_CACHE}" \
		EXTRACT_SUFX=".gem"

RUBYGEMBIN=	${LOCALBASE}/bin/gem${RUBY_VER:S/.//}

GEMFILES=	${GEM_NAME}.gem

RUBYGEM_ARGS=-l --no-update-sources --no-ri --install-dir ${PREFIX}/lib/ruby/gems/${RUBY_VER}

WRKSRC=	${WRKDIR}/${PORTNAME}-ruby-1.9-temp

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	rubygem-allison>=0:${PORTSDIR}/devel/rubygem-allison
.else
RUBYGEM_ARGS+=	--no-rdoc
.endif

post-patch:
.for l in 1.8.6 1.8.7 1.9.2 1.9.3
	@${ECHO} lib/io/like-${l}.rb >> ${WRKSRC}/MANIFEST
.endfor
.for f in likestringio.rb rot13filter.rb
	@${RUBY} -i -pe "sub %r|((\s*)require 'io/like')|, %Q|\\\2require 'rubygems'\n\\\1|" ${WRKSRC}/examples/${f}
.endfor

do-build:
	@cd ${BUILD_WRKSRC} && ${RAKE_BIN}

do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} install ${RUBYGEM_ARGS} pkg/${GEMFILES} -- --build-args ${CONFIGURE_ARGS})

post-install:
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${FIND} -ds ${PREFIX}/${GEM_DOC_DIR} -type f -print | ${SED} -E -e \
		's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${GEM_DOC_DIR} -type d -print | ${SED} -E -e \
		's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
.endif
	@${FIND} -ds ${PREFIX}/${GEM_LIB_DIR} -type f -print | ${SED} -E -e \
		's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${GEM_LIB_DIR} -type d -print | ${SED} -E -e \
		's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${GEMS_DIR} 2>/dev/null || true" >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_CMD} "@unexec rmdir %D/${DOC_DIR} 2>/dev/null || true" >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@unexec rmdir %D/${CACHE_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${SPEC_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${GEMS_BASE_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
