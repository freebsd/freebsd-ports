# $FreeBSD$

PORTNAME=	preprocessor-tools
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Framework for extending Haskell's syntax via quick-and-dirty preprocessors

LICENSE=	BSD3CLAUSE

USE_CABAL=	mtl>=1 syb>=0

IGNORE=		Doesn't build with recent GHC version

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
