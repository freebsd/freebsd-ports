# New ports collection makefile for:	haddock
# Date created:				09 May 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	2.4.2
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/haddock/dist/ \
		http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A documentation tool for Haskell

.if !defined(SLAVE)
BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
       		hs-ghc-paths>=0.1.0.5:${PORTSDIR}/devel/hs-ghc-paths
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
       		hs-ghc-paths>=0.1.0.5:${PORTSDIR}/devel/hs-ghc-paths
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4
.else
NO_PKG_REGISTER=
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}

GHC_VERSION=		6.10.4
HADDOCK_VERSION=	${PORTVERSION}

CABAL_CMD=	runghc Setup.lhs

DATADIR=		${PREFIX}/share/${DISTNAME}
HADDOCK_LIBDIR_REL=	lib/${DISTNAME}
DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		DATADIR_REL=${DATADIR_REL} \
		HADDOCK_LIBDIR_REL=${HADDOCK_LIBDIR_REL} \
		HADDOCK_VERSION=${HADDOCK_VERSION} \
		DOCSDIR_REL=${DOCSDIR_REL}

.include <bsd.port.pre.mk>

.if !defined(SLAVE)
PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if ${PORT_HADDOCK} == 11
ECHO_MSG=	${PRINTF} "%b"
IGNORE+=	\n\t The ${LOCALBASE}/bin/haddock executable was already installed\n
IGNORE+=	\t by the lang/ghc port, setting the option WITH_HADDOCK.\n
IGNORE+=	\t You have to reinstall this last one with the right option\n
IGNORE+=	\t WITHOUT_HADDOCK.\n\c
.elif ${PORT_HADDOCK} == 01
ECHO_MSG=	${PRINTF} "%b"
IGNORE+=	\n\t This port depends on the lang/ghc port, which will install\n
IGNORE+=	\t the ${LOCALBASE}/bin/haddock executable, for the WITH_HADDOCK\n
IGNORE+=	\t option was set in it. You have to set the WITHOUT_HADDOCK\n
IGNORE+=	\t options in lang/ghc before to install devel/hs-haddock.\n\c
.endif
.endif

.SILENT:

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/doc/configure.ac

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} build
.if !defined(SLAVE)
	cd ${WRKSRC} && ${CABAL_CMD} register --gen-script
.endif

do-install:
	cd ${WRKSRC} && ${CABAL_CMD} install

post-install:
	${STRIP_CMD} ${PREFIX}/bin/haddock
.if !defined(SLAVE)
	${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${PREFIX}/${HADDOCK_LIBDIR_REL}/register.sh
.endif
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.post.mk>
