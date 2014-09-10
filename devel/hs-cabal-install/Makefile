# $FreeBSD$

PORTNAME=	cabal-install
PORTVERSION=	1.18.0.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage

LICENSE=	BSD3CLAUSE

USE_CABAL=	network>=1 random>=1 HTTP>=4000.0.8 stm>=2.0 zlib>=0.5.3

STANDALONE=	yes
EXECUTABLE=	cabal

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
