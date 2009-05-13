# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	6.8.3
PORTREVISION=	5
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		http://www.haskell.org/ghc/dist/${PORTVERSION}/FreeBSD/:boot \
		${MASTER_SITE_LOCAL:S/$/:boot/}
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source \
		ghc-${PORTVERSION}-src-extralibs${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Compiler for the functional language Haskell

ONLY_FOR_ARCHS=	i386 amd64

GHC_VERSION=	${PORTVERSION}

USE_AUTOTOOLS=	autoconf:262:env
USE_BZIP2=	yes
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

USE_PERL5=	yes
USE_GMAKE=	yes

# The configure process accepts,filters and canonicalises
# the CONFIGURE_TARGET variable. You can read the files
# ${WRKSRC}/configure and ${WRKSRC}/config.sub.
# This is better fixed in the ${WRKSRC}/mk/build.mk.
# You can view below.
GNU_CONFIGURE=	yes

OPTIONS=	PROFILE "Compile for profiling as well" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS+=	DOCS "Install HTML documentation" on
.else
.undef		WITH_DOCS
.endif

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.if ${ARCH} == "i386"
.if ${OSVERSION} >= 700000
DISTFILES+=	ghc-${PORTVERSION}-i386-unknown-freebsd7-boot${EXTRACT_SUFX}:boot
.else
DISTFILES+=	ghc-${PORTVERSION}-i386-unknown-freebsd6-boot${EXTRACT_SUFX}:boot
.endif
.endif

.if ${ARCH} == "amd64"
.if ${OSVERSION} >= 700000
DISTFILES+=	ghc-${PORTVERSION}-x86_64-unknown-freebsd7-boot${EXTRACT_SUFX}:boot
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

# This port builds by downloading a minimal binary distribution of GHC and
# using that to bootstrap.
BOOT_DIR=	${WRKDIR}/ghc-${GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${GHC_VERSION}

CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC}  --with-gcc=${CC} \
	--with-gmp-includes=${LOCALBASE}/include --with-gmp-libraries=${LOCALBASE}/lib
# libgmp:
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp
MAKE_ENV+=	TMPDIR=${TMPDIR}
EXCLUDELIBS=	ALUT GLUT HGL OpenAL OpenGL X11

# Defining WITH_DOCS:
# An in place installation and registration of haddock will be
# activated. In this way it's possible to use it directly into
# the build tree, without needing to install it. At the end
# you could view the output of: ${BOOT_GHC} describe haddock
.if defined(WITH_DOCS)

MASTER_SITES+=	http://hackage.haskell.org/packages/archive/haddock/2.1.0/:docs \
		ftp://ftp.cs.york.ac.uk/pub/haskell/contrib/:docs

DISTFILES+=	haddock-2.1.0.tar.gz:docs \
		hscolour-1.12.tar.gz:docs

EXTRACT_ONLY=	${_DISTFILES:C/hscolour.*$//g:C/haddock.*$//g}

MAN1=		ghc.1

SUB_FILES=	pkg-message.haddock

SLAVES_PREFIX=		${WRKDIR}/slaves_prefix
SLAVES_WRKDIRPREFIX=	${WRKDIR}/slaves_wrkdirprefix
SLAVES_MAKE_ARGS=	-DSLAVE PREFIX=${SLAVES_PREFIX} WRKDIRPREFIX=${SLAVES_WRKDIRPREFIX}

MAKE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}

BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
.endif

post-extract:
	@${ECHO} >> ${WRKSRC}/mk/build.mk "docdir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "htmldir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "mandir = ${PREFIX}/man"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "infodir = ${PREFIX}/info"
.if defined(WITHOUT_PROFILE)
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays ="
.endif
.if defined(WITH_DOCS)
	@${ECHO} >> ${WRKSRC}/mk/build.mk "XMLDocWays = html"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HADDOCK_DOCS = YES"
.endif

	@cd ${WRKSRC}/libraries && ${RM} -rf ${EXCLUDELIBS}

post-patch:
	@${REINPLACE_CMD} s+%%LOCALBASE%%+${LOCALBASE}+ \
		${WRKSRC}/rts/package.conf.in

pre-configure:
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} --prefix=${BOOT_DIR})
	@(cd ${BOOT_DIR} && ${GMAKE} install)

# Defining WITH_DOCS:
# Defining "SLAVE" in devel/hs-haddock and
# print/hs-hscolour flips the building process
# functionally to this port.
.if defined(WITH_DOCS)
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} "  WARNING: Now Haddock and HsColour will be built, the respective    "
	@${ECHO_MSG} "           ports won't be installed, but it takes place an in-place  "
	@${ECHO_MSG} "           installation and registration of both.                    "
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} ""
	@sleep 3

	@${MKDIR} ${SLAVES_PREFIX}
	@${MKDIR} ${SLAVES_WRKDIRPREFIX}

	@(cd ${PORTSDIR}/devel/hs-haddock && \
		${SETENV} PATH=${BOOT_DIR}/bin:${PATH} ${MAKE} ${SLAVES_MAKE_ARGS} install)

	@(cd ${PORTSDIR}/print/hs-hscolour && \
		${SETENV} PATH=${BOOT_DIR}/bin:${PATH} ${MAKE} ${SLAVES_MAKE_ARGS} install)
.endif

pre-build:
	@${MKDIR} ${TMPDIR}

post-install:
	# cabalised hs-foo-ghc ports
	@${MKDIR} ${PREFIX}/lib/ghc-${PORTVERSION}/cabal
	@${MKDIR} ${PREFIX}/share/doc/ghc-${GHC_VERSION}/cabal

.if defined(WITH_DOCS)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-docs)

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif
	@${RM} -f ${PREFIX}/lib/ghc-${PORTVERSION}/package.conf.old

.include <bsd.port.post.mk>
