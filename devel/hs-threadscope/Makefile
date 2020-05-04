# $FreeBSD$

PORTNAME=	threadscope
PORTVERSION=	0.2.12
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cabal gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

USE_CABAL=	alex-3.2.5 \
		cairo-0.13.8.0 \
		exceptions-0.10.4 \
		file-embed-0.0.11.2 \
		ghc-events-0.12.0 \
		glib-0.13.8.0 \
		gtk2hs-buildtools-0.13.8.0 \
		gtk-0.15.4 \
		happy-1.19.12 \
		hashable-1.3.0.0 \
		hashtables-1.2.3.4 \
		pango-0.13.8.0 \
		primitive-0.7.0.1 \
		random-1.1_1 \
		temporary-1.3 \
		utf8-string-1.0.1.1_3 \
		vector-0.12.1.2

.include <bsd.port.mk>
