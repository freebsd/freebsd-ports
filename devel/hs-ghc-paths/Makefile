# New ports collection makefile for: hs-ghc-paths
# Date created:        July 09 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$

PORTNAME=	ghc-paths
PORTVERSION=	0.1.0.5
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Utility looking for GHC installation directories

.if !defined(SLAVE)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.else
NO_PKG_REGISTER=
.endif

GHC_VERSION=		6.10.4
GHC-PATHS_VERSION=	${PORTVERSION}

CABAL_CMD=	runghc Setup.hs

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
GHC-PATHS_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		GHC-PATHS_VERSION=${GHC-PATHS_VERSION} \
		GHC-PATHS_LIBDIR_REL=${GHC-PATHS_LIBDIR_REL}

.SILENT:

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
.if !defined(SLAVE)
	${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${PREFIX}/${GHC-PATHS_LIBDIR_REL}/register.sh
.endif
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
