# New ports collection makefile for: hs-hoogle
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hoogle
PORTVERSION=	4.0.7
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell API Search

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	safe uniplate

STANDALONE=	yes
EXECUTABLE=	hoogle

PORTDATA=	*

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
