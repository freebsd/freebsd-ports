# New ports collection makefile for: hs-threadscope
# Date created:        December 6, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	threadscope
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A graphical tool for profiling parallel Haskell programs

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	cairo ghc-events>=0.3 glib gtk>=0.12 gtk2hs-buildtools mtl \
		pango

EXECUTABLE=	threadscope
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
