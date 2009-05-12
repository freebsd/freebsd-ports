# New ports collection makefile for:	haddock
# Date created:				09 May 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/haddock/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A documentation tool for Haskell

.if !defined(SLAVE)
BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.else
NO_PKG_REGISTER=
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}

GHC_VERSION=	 6.8.3
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

.SILENT:

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} build --ghc-option="-package process-1.0.0.1"
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

.include <bsd.port.mk>
