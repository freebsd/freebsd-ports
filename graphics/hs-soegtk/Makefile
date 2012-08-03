# New ports collection makefile for: hs-soegtk
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	soegtk
PORTVERSION=	0.12.1
PORTREVISION=	3
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	GUI functions as used in the book "The Haskell School of Expression"

LICENSE=	LGPL21
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	cairo>=0.12 gtk>=0.11 mtl stm>=2
USE_GNOME=	gtk20

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
