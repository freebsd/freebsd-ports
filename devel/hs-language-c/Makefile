# New ports collection makefile for:	hs-language-c-ghc
# Date created:				March 2, 2009
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	language-c
PORTVERSION=	0.3.2.1
PORTREVISION=	4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Analysis and generation of C code in Haskell

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_ALEX=	yes
USE_HAPPY=	yes
USE_CABAL=	syb

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
