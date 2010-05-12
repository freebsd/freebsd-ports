# New ports collection makefile for: hs-ghc-paths
# Date created:        July 09 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$

PORTNAME=	ghc-paths
PORTVERSION=	0.1.0.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	Utility looking for GHC installation directories

CABAL_SETUP=	Setup.hs

.if defined(SLAVE)
GHC_CMD=	ghc
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
