# $FreeBSD$

PORTNAME=	threadscope
PORTVERSION=	0.2.14
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cabal gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

USE_CABAL=	alex-3.2.6 \
		cairo-0.13.8.1 \
		exceptions-0.10.4_1 \
		file-embed-0.0.13.0 \
		ghc-events-0.15.1 \
		glib-0.13.8.1 \
		gtk-0.15.5 \
		gtk2hs-buildtools-0.13.8.0 \
		happy-1.20.0 \
		hashable-1.3.1.0 \
		hashtables-1.2.4.1 \
		pango-0.13.8.1 \
		primitive-0.7.1.0_2 \
		random-1.2.0_5 \
		splitmix-0.1.0.3 \
		temporary-1.3 \
		utf8-string-1.0.2 \
		vector-0.12.2.0

.include <bsd.port.mk>
