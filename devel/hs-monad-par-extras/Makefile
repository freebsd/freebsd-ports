# New ports collection makefile for: hs-monad-par-extras
# Date created:        May 9, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	monad-par-extras
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Combinators and extra features for Par monads

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	abstract-par>=0.3 cereal>=0.3 mtl>=2.0 random>=1.0 \
		transformers>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
