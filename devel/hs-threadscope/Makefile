# $FreeBSD$

PORTNAME=	threadscope
PORTVERSION=	0.2.11.1
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	happy:devel/hs-happy
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cabal gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

USE_CABAL=	alex-3.2.4 cairo-0.13.6.0 exceptions-0.10.0_2 file-embed-0.0.11 \
		ghc-events-0.8.0.1 gio-0.13.6.0 glib-0.13.7.0 \
		gtk2hs-buildtools-0.13.5.0 gtk-0.15.2 happy-1.19.9_3 hashable-1.2.7.0_1 \
		hashtables-1.2.3.1 pango-0.13.6.0 primitive-0.6.4.0_1 random-1.1_1 \
		temporary-1.3 transformers-compat-0.6.2 utf8-string-1.0.1.1_3 \
		vector-0.12.0.2

.include <bsd.port.mk>
