# New ports collection makefile for: hs-haskeline
# Date created:        July 09 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$

PORTNAME=	haskeline
PORTVERSION=	0.6.2.2
CATEGORIES=	devel haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	A command-line interface for user input, written in Haskell

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	utf8-string>=0.3.6
USE_ICONV=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
