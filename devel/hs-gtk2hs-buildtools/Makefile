# $FreeBSD$

PORTNAME=	gtk2hs-buildtools
PORTVERSION=	0.12.4
PORTREVISION=	5
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tools to build the Gtk2Hs suite of User Interface Libraries

LICENSE=	GPLv2

USE_CABAL=	random
USE_ALEX=	yes
USE_HAPPY=	yes

EXECUTABLE=	gtk2hsTypeGen gtk2hsHookGenerator gtk2hsC2hs

STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
