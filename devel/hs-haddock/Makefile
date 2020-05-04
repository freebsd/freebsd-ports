# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	2.23.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation-generation tool for Haskell libraries

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	ghc-paths-0.1.0.12_1 haddock-api-2.23.1 haddock-library-1.8.0_1

haddock_DATADIR_VARS=	haddock-api

post-install:
	cd ${WRKSRC}/haddock-api-${PORTVERSION}/resources/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
