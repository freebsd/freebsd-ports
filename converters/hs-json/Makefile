# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	json
PORTVERSION=	0.7
PORTREVISION=	8
CATEGORIES=	converters haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Support for serialising Haskell to and from JSON

LICENSE=	BSD3CLAUSE

USE_CABAL=	mtl syb>=0.3.3 text

FLAGS_ENABLE=	split-base generic
FLAGS_DISABLE=	parse pretty mapdict

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
