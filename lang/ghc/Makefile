# Created by: Simon Marlow <simonmar@microsoft.com>
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	${GHC_VERSION}
PORTREVISION=	2
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		LOCAL/pgj/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for the functional language Haskell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	i386 amd64

GHC_VERSION=		8.0.2
HSCOLOUR_VERSION=	1.24.1

DATADIR=	${PREFIX}/share/ghc-${GHC_VERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/ghc-${GHC_VERSION}

CONFLICTS=	ghc-7.4.* ghc-7.6.* ghc-7.8.* ghc-7.10.*

LIB_DEPENDS+=	libgmp.so:math/gmp

USES=		autoreconf gmake iconv:translit localbase:ldflags ncurses perl5 tar:xz
USE_LOCALE=	en_US.UTF-8
USE_PERL5=	build

# The configure process accepts,filters and canonicalises
# the CONFIGURE_TARGET variable. You can read the files
# ${WRKSRC}/configure and ${WRKSRC}/config.sub.
# This is better fixed in files/build.mk.in
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=		--with-ld=${LD} \
			--with-gmp-includes=${LOCALBASE}/include \
			--with-gmp-libraries=${LOCALBASE}/lib \
			--with-iconv-includes=${LOCALBASE}/include \
			--with-iconv-libraries=${LOCALBASE}/lib

SUB_FILES=		build.mk \
			build.boot.mk
SUB_LIST=		GHC_VERSION=${GHC_VERSION} \
			NCURSESINC="${NCURSESINC}" NCURSESLIB="${NCURSESLIB}" \
			CFLAGS="${CFLAGS}"

OPTIONS_GROUP=		BOOTSTRAP
BOOTSTRAP_DESC=		Bootsrap using installed ghc
OPTIONS_GROUP_BOOTSTRAP=BOOT BOOTH
OPTIONS_DEFINE=		DYNAMIC PROFILE DOCS
OPTIONS_SUB=		yes

OPTIONS_DEFAULT=	PROFILE DYNAMIC

BOOT_DESC=		Use installed GHC for bootstrapping
BOOTH_DESC=		Use installed HsColour for bootstrapping
PROFILE_DESC=		Add support for performance profiling
DYNAMIC_DESC=		Add support for dynamic linking
DOCS_DESC=		Install HTML documentation

DYNAMIC_CONFIGURE_ARGS=	--with-system-libffi \
			--with-ffi-includes=${LOCALBASE}/include \
			--with-ffi-libraries=${LOCALBASE}/lib
# The version number is needed as lang/gcc installs a different version
DYNAMIC_LIB_DEPENDS=	libffi.so.6:devel/libffi

# Append substitutions for build.mk -- the files uses '#' as comments
BOOT_SUB_LIST=		HSC2HS=${LOCALBASE}/bin/hsc2hs
BOOT_SUB_LIST_OFF=	HSC2HS=${BOOT_HSC2HS}

DOCS_BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx

DYNAMIC_SUB_LIST=	WITH_DYNAMIC=""
DYNAMIC_SUB_LIST_OFF=	WITH_DYNAMIC="\#"

PROFILE_SUB_LIST=	WITH_PROFILE=""
PROFILE_SUB_LIST_OFF=	WITH_PROFILE="\#"

DOCS_SUB_LIST=		WITH_DOCS="YES"
DOCS_SUB_LIST_OFF=	WITH_DOCS="NO"

LOCALBASE?=	/usr/local

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MBOOT)
BOOT_GHC_VERSION=	7.10.2
DISTFILES+=		ghc-${BOOT_GHC_VERSION}-boot-${ARCH}-freebsd${EXTRACT_SUFX}:boot
.endif # MBOOT

# LLVM is still not properly supported, further it does not make sense to have
# to depend on old llvm ports that will be removed from the ports soon.
# So for now, stick to GCC.
# https://ghc.haskell.org/trac/ghc/wiki/Commentary/Compiler/Backends/LLVM/Installing
# We should however investigate whether base's clang is enough to build ghc&co.
# This will likely require some modifications to compiler/main/*hs
USE_GCC=		yes
CONFIGURE_ARGS+=	-with-gcc=${CC}
.if empty(PORT_OPTIONS:MBOOT)
CONFIGURE_ARGS_BOOT+=	--with-gcc=${CC}
.endif

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
GHC_LIBDIR=	${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION}
GHC_LIBDIR_REL=	lib/ghc-${GHC_VERSION}

PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} GHC_LIBDIR=${GHC_LIBDIR_REL}

HACKAGE_SITE?=	http://hackage.haskell.org/package/

.if empty(PORT_OPTIONS:MBOOT)
BOOT_DIR=	${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}
BOOT_GHC-PKG=	${BOOT_DIR}/bin/ghc-pkg-${BOOT_GHC_VERSION}
BOOT_HSC2HS=	${BOOT_DIR}/bin/hsc2hs

SLAVE_CMD=	${SETENV} PATH=${BOOT_DIR}/bin:${PATH}

CONFIGURE_ARGS_BOOT+=	--prefix=${BOOT_DIR} --with-ld=${LD}
CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC}
.else # MBOOT
SLAVE_CMD=		# empty
CONFIGURE_ARGS+=	--with-ghc=${LOCALBASE}/bin/ghc
.endif # MBOOT

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp

# Defining with documentation:
# An in place installation and registration of hscolour will be
# activated. In this way it's possible to use it directly into
# the build tree, without needing to install it. At the end
# you could view the output of: ${BOOT_GHC} describe hscolour

.if ${PORT_OPTIONS:MDOCS}

.  if empty(PORT_OPTIONS:MBOOTH)

MASTER_SITES+=	${HACKAGE_SITE}hscolour-${HSCOLOUR_VERSION}/:docs
DISTFILES+=	hscolour-${HSCOLOUR_VERSION}.tar.gz:docs

EXTRACT_ONLY=	${_DISTFILES:C/hscolour.*$//g}

.  endif # MBOOTH

.  if empty(PORT_OPTIONS:MBOOTH)

SLAVES_PREFIX=		${WRKDIR}/slaves_prefix
SLAVES_WRKDIRPREFIX=	${WRKDIR}/slaves_wrkdirprefix

MAKE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}

.  endif # MBOOTH

.endif # MDOCS

post-extract:
.if empty(PORT_OPTIONS:MBOOT) && ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200031
	@${REINPLACE_CMD} -e 's|@SettingsCCompilerLinkFlags@|& -Wl,--wrap=readdir_r,--wrap=stat,--wrap=lstat,--wrap=fstat,--wrap=mknod|' ${BOOT_DIR}/settings.in
.endif

# %%PORTDOCS%%%%DOCSDIR%%/html/libraries/doc-index-V.html
post-install-script:
	${FIND} -ds ${GHC_LIBDIR} -type f -print | ${SED} -E \
		-e 's,^${STAGEDIR}${PREFIX}/?,,' \
		-e '/^${GHC_LIBDIR:C/\//\\\//g}\/package.conf.d\/package\.cache/s|^|@comment |g' \
		>> ${TMPPLIST}
	${FIND} -ds ${STAGEDIR}${DOCSDIR} -type f -print | ${SED} -E \
		-e 's,^${STAGEDIR}${PREFIX}/?,,' \
		-e '/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/doc-index-[^.]+\.html/s|^|@comment |g' \
		-e '/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/index[^\/.]*\.html/s|^|@comment|g' \
		-e '/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/[^\/]+\.png/s|^|@comment |g' \
		>> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	# Cleanup the indexen created by gen_contents_index
	${ECHO} "@postunexec ${RM} %D/${DOCSDIR_REL}/html/libraries/doc-index-*.html" >> ${TMPPLIST}
	${ECHO} "@postunexec ${RM} %D/${DOCSDIR_REL}/html/libraries/index*.html" >> ${TMPPLIST}
	${ECHO} "@postunexec ${RM} %D/${DOCSDIR_REL}/html/libraries/*.png" >> ${TMPPLIST}
.endif
	${ECHO} '@postunexec ${RM} %D/${GHC_LIBDIR_REL}/package.conf.d/package.cache' >>${TMPPLIST}
	${ECHO} "@postexec %D/bin/ghc-pkg recache" >>${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	${ECHO} '@postexec ${SH} -c "cd %D/${DOCSDIR_REL}/html/libraries && ./gen_contents_index"' >> ${TMPPLIST}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|; \
		s|%%AR%%|${AR}|; \
		s|%%LD%%|${LD}|' \
		${WRKSRC}/libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs

pre-configure: apply-slist
	# Copy the subbed build.mk to the proper position
	${CP} ${WRKDIR}/build.mk ${WRKSRC}/mk/build.mk

	@${MKDIR} ${TMPDIR}
.if empty(PORT_OPTIONS:MBOOTH) && ${OPSYS} == FreeBSD && \
    ${OSVERSION} >= 1200031
	${CC} ${CFLAGS} -c -o ${BOOT_DIR}/wrap.o ${PATCHDIR}/wrap.c
	for x in ${BOOT_DIR}/rts/dist/build/libCffi*.a; do \
	    ${AR} q $$x ${BOOT_DIR}/wrap.o; ${RANLIB} $$x; \
	done
	rm ${BOOT_DIR}/wrap.o
.endif # Do not merge, prev condition need to grow OSVER check.
.if empty(PORT_OPTIONS:MBOOT)
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS_BOOT})
	@(cd ${BOOT_DIR} && PACKAGES='' ${MAKE_CMD} install)
.endif

.if ${PORT_OPTIONS:MDOCS} && empty(PORT_OPTIONS:MBOOTH)
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "  WARNING: Now HsColour will be built, the respective port will not   "
	@${ECHO_MSG} "           be installed, but an in-place installation and             "
	@${ECHO_MSG} "           registration of both takes place.                          "
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} ""
	@sleep 3

	@${MKDIR} ${SLAVES_PREFIX}
	@${MKDIR} ${SLAVES_WRKDIRPREFIX}

	@(cd ${SLAVES_WRKDIRPREFIX} && \
		${TAR} xvf ${DISTDIR}/hscolour-${HSCOLOUR_VERSION}.tar.gz && \
		cd hscolour-${HSCOLOUR_VERSION} && \
		${SLAVE_CMD} ghc --make -o Setup Setup.hs -package Cabal && \
		${SLAVE_CMD} ./Setup configure --ghc --prefix=${SLAVES_PREFIX} --with-gcc=${CC} --with-ld=${LD} && \
		${SLAVE_CMD} ./Setup build && \
		${SLAVE_CMD} ./Setup install)
.endif

_EXECUTABLES=	${STAGEDIR}${PREFIX}/bin/hp2ps \
		${GHC_LIBDIR}/bin/unlit \
		${GHC_LIBDIR}/bin/hpc \
		${GHC_LIBDIR}/bin/ghc-iserv \
		${GHC_LIBDIR}/bin/ghc-pkg \
		${GHC_LIBDIR}/bin/hsc2hs \
		${GHC_LIBDIR}/bin/runghc \
		${GHC_LIBDIR}/bin/ghc

.if ${PORT_OPTIONS:MPROFILE}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/ghc-iserv-prof
.endif
.if ${PORT_OPTIONS:MDYNAMIC}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/ghc-iserv-dyn
.endif
.if ${PORT_OPTIONS:MDOCS}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/haddock
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/haddock
.if ${PORT_OPTIONS:MDOCS}
	${LN} -sf haddock-ghc-${GHC_VERSION} ${STAGEDIR}${PREFIX}/bin/haddock
.endif
	(for f in ${_EXECUTABLES} $$(${FIND} ${GHC_LIBDIR} -name '*.so'); do \
		${STRIP_CMD} $$f; done)

.include <bsd.port.mk>

# Create a bootstrap compiler tar ball: run this in an interactive poudriere jail
.PHONY: create-bootstrap
create-bootstrap:
	@${ECHO} "TODO: https://github.com/freebsd-haskell/ports/wiki/Updating-the-Bootstrap-Compiler"
	cd ${WRKSCR} \
	&& ${CP} ${WRKDIR}/build.boot.mk mk \
	&& setenv ${CONFIGURE_ENV} ./configure	--with-iconv-includes=${LOCALBASE}/include \
						--with-iconv-libraries=${LOCALBASE}/lib \
						--with-gcc=${CC} \
						--with-ld=${LD} \
	&& make binary-dist TAR_COMP=xz \\
	&& mv ghc-${GHC_VERSION}-boot-${GHC_ARCH}-unknown-freebsd.tar.xz /tmp/ghc-${GHC_VERSION}-${ARCH}-freebsd${FREEBSD_MAJOR_VERSION}-boot.tar.xz
