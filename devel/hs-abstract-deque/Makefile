# New ports collection makefile for: hs-abstract-deque
# Date created:        May 9, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	abstract-deque
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Abstract, parameterized interface to mutable Deques

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	HUnit IORefCAS>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
