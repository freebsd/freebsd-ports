# $FreeBSD$

PORTNAME=	cabal-install
PORTVERSION=	1.22.6.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage

LICENSE=	BSD3CLAUSE

USE_CABAL=	HTTP>=4000.2.5 mtl>=2.0 network>=2.6 network-uri>=2.6 \
		random>=1 stm>=2.0 zlib>=0.5.3

STANDALONE=	yes
EXECUTABLE=	cabal

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
