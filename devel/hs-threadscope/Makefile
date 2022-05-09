PORTNAME=	threadscope
PORTVERSION=	0.2.14
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cabal gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

USE_CABAL=	alex-3.2.7.1 \
		cairo-0.13.8.2 \
		file-embed-0.0.15.0 \
		ghc-events-0.17.0.3 \
		gio-0.13.8.2 \
		glib-0.13.8.2 \
		gtk-0.15.7 \
		gtk2hs-buildtools-0.13.8.3 \
		happy-1.20.0_1 \
		hashable-1.4.0.2 \
		hashtables-1.3 \
		pango-0.13.8.2 \
		primitive-0.7.3.0 \
		random-1.2.1.1 \
		splitmix-0.1.0.4 \
		temporary-1.3 \
		utf8-string-1.0.2 \
		vector-0.12.3.1_1

BROKEN_aarch64=	 ld.lld: error: relocation R_AARCH64_PREL64 cannot be used against symbol ... recompile with -fPIC

.include <bsd.port.mk>
