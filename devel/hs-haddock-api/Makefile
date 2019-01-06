# $FreeBSD$

PORTNAME=	haddock-api
PORTVERSION=	2.21.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation-generation tool for Haskell libraries

LICENSE=	BSD3CLAUSE

BROKEN=		Doesn't build with recent GHC

USE_CABAL=	ghc-paths haddock-library>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
