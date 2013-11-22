# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	DeepArrow
PORTVERSION=	0.3.7
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Arrows for "deep application"

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

LICENSE=	BSD

USE_CABAL=	haskell-src mtl TypeCompose>=0.9.5

BROKEN=		does not build with GHC 7.6

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
