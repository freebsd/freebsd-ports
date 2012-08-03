# New ports collection makefile for:	hs-cabal-install
# Date created:		2010-08-17
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cabal-install
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The command-line interface for Cabal and Hackage

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	network>=1 random>=1 HTTP>=4000.0.2 zlib>=0.4

STANDALONE=	yes
EXECUTABLE=	cabal

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
