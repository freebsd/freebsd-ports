# $FreeBSD$

PORTNAME=	gconf
PORTVERSION=	0.12.5.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GNOME configuration database system

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	glib>=0.12.5.0 gtk2hs-buildtools
USE_GNOME=	gconf2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
