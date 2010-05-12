# New ports collection makefile for: hs-show
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	show
PORTVERSION=	0.3.3
CATEGORIES=	devel haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	Haskell Show instances for Lambdabot

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	smallcheck>=0.4

CONFIGURE_ARGS+=	--constraint='base<4'

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
