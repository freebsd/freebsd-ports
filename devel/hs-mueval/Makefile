# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	mueval
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Safely evaluate Haskell expressions

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	hint>=0.3.1 mtl show>=0.3 utf8-string

EXECUTABLE=	mueval mueval-core

SHOW_PKGMSG=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
