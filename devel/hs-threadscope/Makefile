PORTNAME=	threadscope
PORTVERSION=	0.2.14.1
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs
WWW=		https://www.haskell.org/haskellwiki/ThreadScope

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cabal gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

USE_CABAL=	alex-3.5.2.0 \
		ansi-terminal-1.1.2 \
		ansi-terminal-types-1.1 \
		cairo-0.13.11.0 \
		colour-2.3.6 \
		data-array-byte-0.1.0.1_4 \
		file-embed-0.0.16.0 \
		ghc-events-0.20.0.0_1 \
		gio-0.13.11.0 \
		glib-0.13.11.0 \
		gtk-0.15.9 \
		gtk2hs-buildtools-0.13.11.0 \
		happy-2.1.4 \
		happy-lib-2.1.4 \
		hashable-1.4.7.0 \
		hashtables-1.4.2 \
		optparse-applicative-0.18.1.0_1 \
		os-string-2.0.7 \
		pango-0.13.11.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0_2 \
		random-1.3.0 \
		splitmix-0.1.1 \
		tagged-0.8.9 \
		tasty-1.5.3 \
		temporary-1.3 \
		transformers-compat-0.7.2 \
		utf8-string-1.0.2 \
		vector-0.13.2.0_1 \
		vector-stream-0.1.0.1_3

CABAL_REVISION=	3

BROKEN_aarch64=	 ld.lld: error: relocation R_AARCH64_PREL64 cannot be used against symbol ... recompile with -fPIC

.include <bsd.port.mk>
