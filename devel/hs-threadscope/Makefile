PORTNAME=	threadscope
PORTVERSION=	0.2.15.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs
WWW=		https://www.haskell.org/haskellwiki/ThreadScope

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cabal gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf glib20 gtk30

USE_CABAL=	alex-3.5.3.0 \
		ansi-terminal-1.1.2 \
		ansi-terminal-types-1.1 \
		cairo-0.13.12.0 \
		colour-2.3.6 \
		file-embed-0.0.16.0 \
		ghc-events-0.20.0.0_2 \
		gio-0.13.12.0 \
		glib-0.13.12.0 \
		gtk2hs-buildtools-0.13.12.0 \
		gtk3-0.15.10 \
		happy-2.1.5 \
		happy-lib-2.1.5 \
		hashable-1.5.0.0_1 \
		hashtables-1.4.2 \
		optparse-applicative-0.18.1.0_1 \
		os-string-2.0.7 \
		pango-0.13.12.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		random-1.3.1 \
		splitmix-0.1.1 \
		tagged-0.8.9 \
		tasty-1.5.3_1 \
		temporary-1.3 \
		transformers-compat-0.7.2 \
		utf8-string-1.0.2 \
		vector-0.13.2.0_1 \
		vector-stream-0.1.0.1_3

.include <bsd.port.mk>
