PORTNAME=	ghcprofview
PORTVERSION=	0.1.0.2
PORTREVISION=	7
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical viewer for GHC profile files
WWW=		https://github.com/portnov/ghcprofview-hs

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		cabal gnome pkgconfig

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 introspection pango

USE_CABAL=	OneTuple-0.4.1.1 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_3 \
		ansi-terminal-1.0 \
		ansi-terminal-types-0.11.5_1 \
		assoc-1.1 \
		async-2.2.4_3 \
		attoparsec-0.14.4_3 \
		base-compat-0.13.0 \
		base-compat-batteries-0.13.0 \
		base-orphans-0.9.0 \
		bifunctors-5.6.1 \
		bitvec-1.1.4.0 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_4 \
		cabal-doctest-1.0.9_3 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		conduit-1.3.4.3_1 \
		conduit-extra-1.3.6 \
		contravariant-1.5.5 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_4 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		foldable1-classes-compat-0.1_2 \
		generically-0.1.1_1 \
		ghc-prof-1.4.1.12 \
		gi-atk-2.0.27 \
		gi-cairo-1.0.29 \
		gi-freetype2-2.0.4 \
		gi-gdk-3.0.28 \
		gi-gdkpixbuf-2.0.31 \
		gi-gio-2.0.32 \
		gi-glib-2.0.29 \
		gi-gmodule-2.0.5 \
		gi-gobject-2.0.30 \
		gi-gtk-3.0.41 \
		gi-harfbuzz-0.0.9 \
		gi-pango-1.0.29 \
		happy-1.20.1.1 \
		hashable-1.4.2.0_1 \
		haskell-gi-0.26.4 \
		haskell-gi-base-0.26.3 \
		haskell-gi-overloading-1.0 \
		haskell-lexer-1.1.1 \
		hsc2hs-0.68.9 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		integer-logarithms-1.0.3.1_4 \
		mono-traversable-1.0.15.3 \
		network-3.1.3.0 \
		pretty-show-1.10 \
		primitive-0.8.0.0 \
		random-1.2.1.1 \
		regex-base-0.94.0.2_1 \
		regex-tdfa-1.3.2 \
		resourcet-1.3.0 \
		safe-0.3.19 \
		scientific-0.3.7.0_5 \
		semialign-1.3 \
		semigroupoids-6.0.0.1 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_2 \
		streaming-commons-0.2.2.6 \
		strict-0.5 \
		tagged-0.8.7 \
		text-short-0.1.5_2 \
		th-abstraction-0.5.0.0 \
		these-1.2 \
		time-compat-1.9.6.1_5 \
		transformers-compat-0.7.2 \
		typed-process-0.2.11.0 \
		unliftio-core-0.2.1.0_2 \
		unordered-containers-0.2.19.1_2 \
		uuid-types-1.0.5_4 \
		vector-0.13.0.0_3 \
		vector-algorithms-0.9.0.1_2 \
		vector-stream-0.1.0.0_2 \
		witherable-0.4.2_4 \
		xdg-basedir-0.2.2 \
		xml-conduit-1.9.1.2 \
		xml-types-0.3.8 \
		zlib-0.6.3.0_1

.include <bsd.port.mk>
