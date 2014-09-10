# $FreeBSD$

PORTNAME=	gtk2hs-buildtools
PORTVERSION=	0.12.5.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tools to build the Gtk2Hs suite of User Interface Libraries

LICENSE=	GPLv2

USE_CABAL=	hashtables random
USE_ALEX=	yes
USE_HAPPY=	yes

EXECUTABLE=	gtk2hsTypeGen gtk2hsHookGenerator gtk2hsC2hs

STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
