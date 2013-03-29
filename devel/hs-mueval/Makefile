# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	mueval
PORTVERSION=	0.9
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Safely evaluate pure Haskell expressions

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	hint>=0.3.1 mtl>2 show>=0.3 simple-reflect utf8-string

EXECUTABLE=	mueval mueval-core

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
