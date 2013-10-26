# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	hoogle
PORTVERSION=	4.2.16
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell API Search

LICENSE=	BSD

USE_CABAL=	blaze-builder>=0.2 case-insensitive>=0.2 cmdargs>=0.7 \
		conduit>=0.2 haskell-src-exts>=1.12 http-types>=0.7 \
		parsec>=2.1 random safe tagsoup>=0.11 transformers>=0.2 \
		uniplate>=1.6 wai>=1.1 warp>=1.1

EXECUTABLE=	hoogle

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
