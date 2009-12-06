# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	6.10.4
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		${MASTER_SITE_LOCAL:S/$/:boot/} \
		http://www.autistici.org/jacula/FreeBSD/:boot \
#		http://haskell.org/ghc/dist/${PORTVERSION}/freebsd/:boot
MASTER_SITE_SUBDIR=	pgj/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source \
		ghc-${PORTVERSION}-src-extralibs${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Compiler for the functional language Haskell

ONLY_FOR_ARCHS=	i386 amd64

GHC_VERSION=		${PORTVERSION}
BOOT_GHC_VERSION=	${GHC_VERSION}
HADDOCK_VERSION=	2.4.2
PORT_HADDOCK_VERSION=	${HADDOCK_VERSION}
BOOT_HADDOCK_VERSION=	${HADDOCK_VERSION}
HSCOLOUR_VERSION=	1.15
GHCPATH_VERSION=	0.1.0.5

USE_AUTOTOOLS=	autoconf:262:env
USE_BZIP2=	yes
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

USE_PERL5=	yes
USE_GMAKE=	yes
USE_ICONV=	yes

# The configure process accepts,filters and canonicalises
# the CONFIGURE_TARGET variable. You can read the files
# ${WRKSRC}/configure and ${WRKSRC}/config.sub.
# This is better fixed in the ${WRKSRC}/mk/build.mk.
# You can view below.
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
OPTIONS=	PROFILE "Compile for profiling as well" on \
		DOCS "Install HTML documentation" on \
		HADDOCK "Use the internal version of Haddock" off \
		TEST "Use the testsuite" off
.else
OPTIONS=	PROFILE "Compile for profiling as well" on \
		HADDOCK "Use the internal version of Haddock" off \
		TEST "Use the testsuite" off
.endif

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if defined(WITH_TEST)
USE_PYTHON_BUILD=	2.5+
DISTFILES+=	testsuite-${PORTVERSION}${EXTRACT_SUFX}:source
SUB_FILES+=	testsuite.sh
SUB_LIST+=	GHC_VERSION=${GHC_VERSION} \
		GMAKE=${GMAKE} \
		WRKDIR=${WRKDIR}
.endif

# Used by devel/hs-haddock & C.
# Haddock: (0|1)(0|1) = (installing|installed)(port|internal)
.if !exists(${LOCALBASE}/bin/haddock)
.  if defined(WITHOUT_HADDOCK)
PORT_HADDOCK=	00
.  else
PORT_HADDOCK=	01
.  endif
.else
.  if exists(${LOCALBASE}/lib/haddock-${PORT_HADDOCK_VERSION}/register.sh)
PORT_HADDOCK=	10
.  else
PORT_HADDOCK=	11
.  endif
.endif

.if defined(WITHOUT_DOCS)
NOPORTDOCS=
.endif

.if ${ARCH} == "i386"
.if ${OSVERSION} >= 800000
DISTFILES+=	ghc-${GHC_VERSION}-i386-jm0-freebsd8-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 700000
DISTFILES+=	ghc-${GHC_VERSION}-i386-jm0-freebsd7-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 600000
DISTFILES+=	ghc-${GHC_VERSION}-i386-jm0-freebsd6-boot${EXTRACT_SUFX}:boot
.endif
.elif ${ARCH} == "amd64"
.if ${OSVERSION} >= 800000
DISTFILES+=	ghc-${GHC_VERSION}-amd64-ash0-freebsd8-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 700000
DISTFILES+=	ghc-${GHC_VERSION}-amd64-ash0-freebsd7-boot${EXTRACT_SUFX}:boot
.else
IGNORE=		unsupported at the moment
.endif
.endif

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
GHC_LIBDIR_REL=	lib/ghc-${GHC_VERSION}
PORTDOCS=	*

# hack to register LICENSE files without portdocs
.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} GHC_LIBDIR_REL=${GHC_LIBDIR_REL} DOCSDIR_REL=${DOCSDIR_REL}

.if defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

.if defined(WITHOUT_HADDOCK)
PLIST_SUB+=	HADDOCK="@comment "
.else
PLIST_SUB+=	HADDOCK=""
.endif

# This port builds by downloading a minimal binary distribution of GHC and
# using that to bootstrap.
BOOT_DIR=	${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}
BOOT_GHC-PKG=	${BOOT_DIR}/bin/ghc-pkg-${BOOT_GHC_VERSION}
BOOT_HSC2HS=	${BOOT_DIR}/bin/hsc2hs

CONFIGURE_ARGS_BOOT=	--prefix=${BOOT_DIR})
CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC} --with-gcc=${CC} \
			--with-gmp-includes=${LOCALBASE}/include \
			--with-gmp-libraries=${LOCALBASE}/lib

# libgmp:
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp
MAKE_ENV+=	TMPDIR=${TMPDIR}

# Defining WITH_DOCS:
# An in place installation and registration of hscolour will be
# activated. In this way it's possible to use it directly into
# the build tree, without needing to install it. At the end
# you could view the output of: ${BOOT_GHC} describe hscolour
.if defined(WITH_DOCS)

MASTER_SITES+=	ftp://ftp.cs.york.ac.uk/pub/haskell/contrib/:docs
DISTFILES+=	hscolour-${HSCOLOUR_VERSION}.tar.gz:docs

# Defining WITHOUT_HADDOCK:
# An in place installation and registration of ghc-path and
# haddock will be activated. In this way it's possible to use
# it directly into the build tree, without needing to use the
# base version of haddock and ghc-paths. At the end you could
# view the output of: ${BOOT_GHC} describe haddock and
# ${BOOT_GHC} describe ghc-paths.
.if defined(WITHOUT_HADDOCK)
MASTER_SITES+=	http://hackage.haskell.org/packages/archive/ghc-paths/${GHCPATH_VERSION}/:docs \
		http://hackage.haskell.org/packages/archive/haddock/${PORT_HADDOCK_VERSION}/:docs

DISTFILES+=	ghc-paths-${GHCPATH_VERSION}.tar.gz:docs \
		haddock-${PORT_HADDOCK_VERSION}.tar.gz:docs
.endif

EXTRACT_ONLY=	${_DISTFILES:C/ghc-paths.*$//g:C/hscolour.*$//g:C/haddock.*$//g}

MAN1=		ghc.1

SLAVES_PREFIX=		${WRKDIR}/slaves_prefix
SLAVES_WRKDIRPREFIX=	${WRKDIR}/slaves_wrkdirprefix
SLAVES_MAKE_ARGS=	-DSLAVE PREFIX=${SLAVES_PREFIX} WRKDIRPREFIX=${SLAVES_WRKDIRPREFIX} PATH=${BOOT_DIR}/bin:${PATH}

MAKE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}

BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
.endif

# For a post installation test, set WITH_TEST and: make clean; make extract;
# make apply-slist; make testsuite
testsuite:
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "  WARNING: Now a test will be performed, this will take a long time!  "
	@${ECHO_MSG} "  For a summary of the test see the final file:                       "
	@${ECHO_MSG} "                                                                      "
	@${ECHO_MSG} "  ${WRKDIR}/sumtest.txt                                               "
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} ""
	@sleep 3
	-@(${CHMOD} a+x ${WRKDIR}/testsuite.sh && cd ${WRKDIR} && ./testsuite.sh)

post-extract:
	@${ECHO} >> ${WRKSRC}/mk/build.mk "docdir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "htmldir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "mandir = ${PREFIX}/man"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "infodir = ${PREFIX}/info"
.if defined(WITH_PROFILE)
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays += p"
.else
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays ="
.endif
.if defined(WITH_DOCS)
	@${ECHO} >> ${WRKSRC}/mk/build.mk "XMLDocWays = html"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HADDOCK_DOCS = YES"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HSCOLOUR_SRCS = YES"
.else
	@${ECHO} >> ${WRKSRC}/mk/build.mk "XMLDocWays ="
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HADDOCK_DOCS ="
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HSCOLOUR_SRCS ="
.endif
	@${ECHO} >> ${WRKSRC}/mk/build.mk "BSD_PATH_TO_HSC2HS = ${BOOT_HSC2HS}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_HC_OPTS += -I${LOCALBASE}/include -L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_CC_OPTS += ${CFLAGS}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_HSC2HS_OPTS += -I${LOCALBASE}/include --lflag=-L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_LD_OPTS += -L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-include-dirs=${LOCALBASE}/include"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-lib-dirs=${LOCALBASE}/lib"

post-patch:
# Hack don't to install the internal haddock.
.if defined(WITHOUT_HADDOCK)
	@${REINPLACE_CMD} -e 's+\(DO_NOT_INSTALL =\)+\1 haddock+' \
		${WRKSRC}/utils/Makefile
.endif

	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/../ghc-${GHC_VERSION}-boot/rts/package.conf.in \
		${WRKSRC}/rts/package.conf.in \
		${WRKSRC}/libraries/Makefile

	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure

pre-configure:
	@${MKDIR} ${TMPDIR}
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS_BOOT}
	@(cd ${BOOT_DIR} && ${GMAKE} install)
	@(${BOOT_GHC-PKG} unregister haddock-${BOOT_HADDOCK_VERSION})
	@(cd ${BOOT_DIR} && ${RM} -rf utils/haddock && ${RM} -f bin/haddock \
			 && ${RM} -f ${GHC_LIBDIR_REL}/haddock && ${RM} -rf ${GHC_LIBDIR_REL}/haddock-${BOOT_HADDOCK_VERSION})

# Defining WITH_DOCS:
# Defining "SLAVE" in devel/hs-ghc-paths devel/hs-haddock and
# print/hs-hscolour flips the building process
# functionally to this port.
.if defined(WITH_DOCS)
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "  WARNING: Now (Ghc-Paths, Haddock and) HsColour will be built, the   "
	@${ECHO_MSG} "           respective ports won't be installed, but it takes place    "
	@${ECHO_MSG} "           an in-place installation and registration of both.         "
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} ""
	@sleep 3

	@${MKDIR} ${SLAVES_PREFIX}
	@${MKDIR} ${SLAVES_WRKDIRPREFIX}

.if defined(WITHOUT_HADDOCK)
	@(cd ${PORTSDIR}/devel/hs-ghc-paths && \
		${MAKE} ${SLAVES_MAKE_ARGS} install)

	@(cd ${PORTSDIR}/devel/hs-haddock && \
		${MAKE} ${SLAVES_MAKE_ARGS} install)
.endif

	@(cd ${PORTSDIR}/print/hs-hscolour && \
		${MAKE} ${SLAVES_MAKE_ARGS} install)
.endif

post-install:
	# cabalised hs-foo-ghc ports
	@${MKDIR} ${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
	@${MKDIR} ${PREFIX}/share/doc/ghc-${GHC_VERSION}/cabal

.if defined(WITH_DOCS)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-docs)
.endif
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.if defined(WITH_TEST)
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} "  The ${WRKDIR}/testsuite-${GHC_VERSION} was created.                "
	@${ECHO_MSG} "  Now \"make testsuite\" and let's wait!                             "
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} ""
.endif

.include <bsd.port.post.mk>
