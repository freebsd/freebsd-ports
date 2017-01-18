# Created by: Simon Marlow <simonmar@microsoft.com>
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	7.10.2
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		LOCAL/pgj/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for the functional language Haskell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	i386 amd64

MAKE_JOBS_NUMBER_LIMIT=		4
NO_CCACHE=	yes

GHC_VERSION=		${PORTVERSION}
HSCOLOUR_VERSION=	1.23
LLVM_VERSION=		35

DATADIR=	${PREFIX}/share/ghc-${GHC_VERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/ghc-${GHC_VERSION}

CONFLICTS=	ghc-7.4.* ghc-7.6.* ghc-7.8.*

LIB_DEPENDS+=	libgmp.so:math/gmp

USES=		autoreconf gmake iconv:translit ncurses perl5 tar:xz
USE_LOCALE=	en_US.UTF-8
USE_PERL5=		build

# The configure process accepts,filters and canonicalises
# the CONFIGURE_TARGET variable. You can read the files
# ${WRKSRC}/configure and ${WRKSRC}/config.sub.
# This is better fixed in the ${WRKSRC}/mk/build.mk.
# You can view below.
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=			PROFILE DYNAMIC LLVM DOCS
OPTIONS_SINGLE=			C_Compiler
OPTIONS_SINGLE_C_Compiler=	GCC PCLANG BCLANG

OPTIONS_DEFAULT=	PROFILE DYNAMIC GCC

BOOT_DESC=		Use installed GHC for bootstrapping
BOOTH_DESC=		Use installed HsColour for bootstrapping
PCLANG_DESC=		Build with Clang from ports
BCLANG_DESC=		Build with Clang from base
PROFILE_DESC=		Add support for performance profiling
DYNAMIC_DESC=		Add support for dynamic linking
LLVM_DESC=		Add support for generating code via LLVM
DOCS_DESC=		Install HTML documentation

LOCALBASE?=	/usr/local

.if exists(${LOCALBASE}/bin/ghc)
OPTIONS_DEFINE+=	BOOT
.endif

.if exists(${LOCALBASE}/bin/HsColour)
OPTIONS_DEFINE+=	BOOTH
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDYNAMIC}
# The version number is needed as lang/gcc installs a different version
LIB_DEPENDS+=	libffi.so.6:devel/libffi
.endif

.if empty(PORT_OPTIONS:MBOOT)

BOOT_GHC_VERSION=	7.10.2
DISTFILES+=		ghc-${BOOT_GHC_VERSION}-boot-${ARCH}-freebsd${EXTRACT_SUFX}:boot

.endif # MBOOT

.if ${PORT_OPTIONS:MPCLANG}
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang${LLVM_VERSION}:lang/clang${LLVM_VERSION}
RUN_DEPENDS+=	${LOCALBASE}/bin/clang${LLVM_VERSION}:lang/clang${LLVM_VERSION}
CC=		${LOCALBASE}/bin/clang${LLVM_VERSION}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VERSION}
CPP=		${LOCALBASE}/bin/clang-cpp${LLVM_VERSION}
LDFLAGS+=	-B${LOCALBASE}/bin
CFLAGS+=	-Qunused-arguments
CONFIGURE_ARGS+=	--with-clang=${CC} --with-gcc=${CC}
USE_BINUTILS=		yes
.if empty(PORT_OPTIONS:MBOOT)
CONFIGURE_ARGS_BOOT+=	--with-clang=${CC} --with-gcc=${CC}
.endif
.elif ${PORT_OPTIONS:MBCLANG}
CC=		/usr/bin/clang
CXX=		/usr/bin/clang++
CPP=		/usr/bin/clang-cpp
CFLAGS+=	-Qunused-arguments
CONFIGURE_ARGS+=	--with-clang=${CC} --with-gcc=${CC}
.else # GCC
USE_GCC=	yes
CONFIGURE_ARGS+=	--with-gcc=${CC}
.if empty(PORT_OPTIONS:MBOOT)
CONFIGURE_ARGS_BOOT+=	--with-gcc=${CC}
.endif
.endif

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
GHC_LIBDIR=	${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION}
GHC_LIBDIR_REL=	lib/ghc-${GHC_VERSION}

PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} GHC_LIBDIR=${GHC_LIBDIR_REL}

HACKAGE_SITE?=		http://hackage.haskell.org/package/

CONFIGURE_ARGS+=	--with-ld=${LD} \
			--with-gmp-includes=${LOCALBASE}/include \
			--with-gmp-libraries=${LOCALBASE}/lib

CONFIGURE_ARGS+=	--with-iconv-includes=${LOCALBASE}/include \
			--with-iconv-libraries=${LOCALBASE}/lib

.if ${PORT_OPTIONS:MDYNAMIC}
CONFIGURE_ARGS+=	--with-system-libffi \
			--with-ffi-includes=${LOCALBASE}/include \
			--with-ffi-libraries=${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MLLVM}
BUILD_DEPENDS+=		${LOCALBASE}/bin/opt${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS+=		${LOCALBASE}/bin/opt${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

CONFIGURE_ARGS+=	--with-opt=${LOCALBASE}/bin/opt${LLVM_VERSION} \
			--with-llc=${LOCALBASE}/bin/llc${LLVM_VERSION}
.endif

.if empty(PORT_OPTIONS:MBOOT)

BOOT_DIR=	${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}
BOOT_GHC-PKG=	${BOOT_DIR}/bin/ghc-pkg-${BOOT_GHC_VERSION}
BOOT_HSC2HS=	${BOOT_DIR}/bin/hsc2hs

SLAVE_CMD=	${SETENV} PATH=${BOOT_DIR}/bin:${PATH}

CONFIGURE_ARGS_BOOT+=	--prefix=${BOOT_DIR} --with-ld=${LD}
CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC}

.else # MBOOT

SLAVE_CMD=	# empty

CONFIGURE_ARGS+=	--with-ghc=${LOCALBASE}/bin/ghc

.endif # MBOOT

# libgmp:
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp

# Defining with documentation:
# An in place installation and registration of hscolour will be
# activated. In this way it's possible to use it directly into
# the build tree, without needing to install it. At the end
# you could view the output of: ${BOOT_GHC} describe hscolour

.if ${PORT_OPTIONS:MDOCS}

.if empty(PORT_OPTIONS:MBOOTH)

MASTER_SITES+=	${HACKAGE_SITE}hscolour-${HSCOLOUR_VERSION}/:docs
DISTFILES+=	hscolour-${HSCOLOUR_VERSION}.tar.gz:docs

EXTRACT_ONLY=	${_DISTFILES:C/hscolour.*$//g}

.endif # MBOOTH

.if empty(PORT_OPTIONS:MBOOTH)

SLAVES_PREFIX=		${WRKDIR}/slaves_prefix
SLAVES_WRKDIRPREFIX=	${WRKDIR}/slaves_wrkdirprefix

MAKE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}

.endif # MBOOTH

BUILD_DEPENDS+=	docbook-xsl>0:textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:textproc/libxslt
.endif

post-extract:
	@${ECHO} >> ${WRKSRC}/mk/build.mk "docdir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "htmldir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "mandir = ${PREFIX}/man"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "infodir = ${PREFIX}/info"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays = v"
.if ${PORT_OPTIONS:MPROFILE}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays += p"
.endif
.if ${PORT_OPTIONS:MDYNAMIC}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays += dyn"
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "XMLDocWays = html"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HADDOCK_DOCS = YES"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HSCOLOUR_SRCS = YES"
.else
	@${ECHO} >> ${WRKSRC}/mk/build.mk "XMLDocWays ="
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HADDOCK_DOCS ="
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HSCOLOUR_SRCS ="
.endif
.if ${PORT_OPTIONS:MBOOT}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "BSD_PATH_TO_HSC2HS = ${LOCALBASE}/bin/hsc2hs"
.else
	@${ECHO} >> ${WRKSRC}/mk/build.mk "BSD_PATH_TO_HSC2HS = ${BOOT_HSC2HS}"
.endif
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_HC_OPTS += -I${NCURSESINC} -L${NCURSESLIB} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
.if ${PORT_OPTIONS:MPCLANG}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_HC_OPTS += -optl=-B${LOCALBASE}/bin"
.endif
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_CC_OPTS += ${CFLAGS}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_HSC2HS_OPTS += -I${LOCALBASE}/include --lflag=-L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_LD_OPTS += -L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-include-dirs=${LOCALBASE}/include"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-lib-dirs=${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "libraries/terminfo_CONFIGURE_OPTS += --configure-option=--with-curses-includes=${NCURSESINC} --configure-option=--with-curses-libraries=${NCURSESLIB}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "V = 0"
.if ${PORT_OPTIONS:MBCLANG} || ${PORT_OPTIONS:MPCLANG}
	@${REINPLACE_CMD} -e 's|@SettingsCCompilerFlags@|& -Qunused-arguments|' ${WRKSRC}/settings.in
.if empty(PORT_OPTIONS:MBOOT)
	@${REINPLACE_CMD} -e 's|@SettingsCCompilerFlags@|& -Qunused-arguments|' ${BOOT_DIR}/settings.in
.endif
.endif

post-install-script:
	@${FIND} -ds ${GHC_LIBDIR} -type f -print | ${SED} -E -e \
		'/^${GHC_LIBDIR:C/\//\\\//g}\/package.conf.d\/package\.cache/d' -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DOCSDIR} -type f -print | ${SED} -E -e \
		'/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/doc-index-[^.]+\.html/d' -e \
		'/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/index[^\/.]*\.html/d' -e \
		'/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/[^\/]+\.png/d' -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	# Cleanup the indexen created by gen_contents_index
	@${ECHO} "@unexec ${RM} %D/${DOCSDIR_REL}/html/libraries/doc-index-*.html" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RM} %D/${DOCSDIR_REL}/html/libraries/index*.html" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RM} %D/${DOCSDIR_REL}/html/libraries/*.png" >> ${TMPPLIST}
.endif
	@${ECHO} '@unexec ${RM} %D/${GHC_LIBDIR_REL}/package.conf.d/package.cache' >>${TMPPLIST}
	@${ECHO} "@exec %D/bin/ghc-pkg recache" >>${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} '@exec ${SH} -c "cd %D/${DOCSDIR_REL}/html/libraries && ./gen_contents_index"' >> ${TMPPLIST}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|; \
		s|%%AR%%|${AR}|; \
		s|%%LD%%|${LD}|' \
		${WRKSRC}/libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs

pre-configure:
	@${MKDIR} ${TMPDIR}
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

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/haddock
.if ${PORT_OPTIONS:MDOCS}
	@${LN} -sf haddock-ghc-${GHC_VERSION} ${STAGEDIR}${PREFIX}/bin/haddock
.endif
	@(for f in ${STAGEDIR}${PREFIX}/bin/hp2ps ${GHC_LIBDIR}/unlit \
	    $$(${FIND} ${GHC_LIBDIR}/bin -type f; ${FIND} ${GHC_LIBDIR} -name '*.so'); do \
	    ${STRIP_CMD} $$f; done)

.include <bsd.port.mk>
