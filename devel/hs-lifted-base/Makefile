# New ports collection makefile for: hs-lifted-base
# Date created:        December 30, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lifted-base
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Lifted IO operations from the base library

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	base-unicode-symbols>=0.1.1 monad-control>=0.3 \
		transformers-base>=0.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
