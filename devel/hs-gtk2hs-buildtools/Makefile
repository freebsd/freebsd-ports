# $FreeBSD$

PORTNAME=	gtk2hs-buildtools
PORTVERSION=	0.13.4.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tools to build the Gtk2Hs suite of User Interface Libraries

LICENSE=	GPLv2

BROKEN=		Doesn't build with recent GHC

USE_CABAL=	hashtables random
USE_ALEX=	yes
USE_HAPPY=	yes
EXECUTABLE=	gtk2hsC2hs gtk2hsHookGenerator gtk2hsTypeGen

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
