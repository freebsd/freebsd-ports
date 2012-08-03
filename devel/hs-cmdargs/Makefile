# New ports collection makefile for: hs-cmdargs
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cmdargs
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command line argument processing

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	transformers>=0.2

EXECUTABLE=	cmdargs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
