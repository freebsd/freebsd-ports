# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	2.22.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation-generation tool for Haskell libraries

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	ghc-paths-0.1.0.9_4 haddock-api-${PORTVERSION} haddock-library-1.7.0

haddock_DATADIR_VARS=	haddock-api

post-install:
	cd ${WRKSRC}/haddock-api-${PORTVERSION}/resources/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
