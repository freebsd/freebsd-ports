# New ports collection makefile for:	hs-hlint
# Date created:		January 2, 2012
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hlint
PORTVERSION=	1.8.30
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Source code suggestions

LICENSE=	GPLv2

CABAL_SETUP=	Setup.hs

USE_CABAL=	cpphs>=1.11 haskell-src-exts>=1.11 hscolour>=1.17 \
		transformers>=0.0 uniplate>=1.5

EXECUTABLE=	hlint

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
