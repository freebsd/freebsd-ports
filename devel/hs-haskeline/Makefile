# New ports collection makefile for: hs-haskeline
# Date created:        July 09 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$

PORTNAME=	haskeline
PORTVERSION=	0.6.4.7
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A command-line interface for user input, written in Haskell

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	mtl>=1.1 utf8-string>=0.3.6
USE_ICONV=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
