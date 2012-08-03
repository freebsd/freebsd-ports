# New ports collection makefile for: hs-monad-control
# Date created:        September 24, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	monad-control
PORTVERSION=	0.3.1.3
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Lift control operations through monad transformers

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	base-unicode-symbols>=0.1.1 transformers>=0.2 \
		transformers-base>=0.4.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
