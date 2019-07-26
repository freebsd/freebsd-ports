# $FreeBSD$

PORTNAME=	ghcprofview
PORTVERSION=	0.1
CATEGORIES=	devel haskell
MASTER_SITES=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical viewer for GHC profile files

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=  happy:devel/hs-happy

USES=		cabal:hpack gnome pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	portnov:${PORTNAME}-hs:026d13bd1aa07197b789d681bb353d96fb2241f8

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 introspection pango

USE_CABAL=	aeson-1.4.4.0 \
		async-2.2.2 \
		attoparsec-0.13.2.2_3 \
		base-compat-0.10.5 \
		base-orphans-0.8.1 \
		blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.1 \
		blaze-markup-0.8.2.2_1 \
		conduit-1.3.1.1 \
		conduit-extra-1.3.4 \
		data-default-class-0.1.2.0 \
		dlist-0.8.0.6_1 \
		exceptions-0.10.2 \
		ghc-prof-1.4.1.5 \
		gi-atk-2.0.20 \
		gi-cairo-1.0.22 \
		gi-gdk-3.0.21 \
		gi-gdkpixbuf-2.0.22 \
		gi-gio-2.0.24 \
		gi-glib-2.0.22 \
		gi-gobject-2.0.21 \
		gi-gtk-3.0.31 \
		gi-pango-1.0.21 \
		happy-1.19.11 \
		hashable-1.3.0.0 \
		haskell-gi-0.22.6 \
		haskell-gi-base-0.22.2 \
		haskell-gi-overloading-1.0 \
		haskell-lexer-1.0.2 \
		hsc2hs-0.68.4 \
		integer-logarithms-1.0.3 \
		mono-traversable-1.0.11.0 \
		network-3.1.0.1 \
		pretty-show-1.9.5 \
		primitive-0.7.0.0 \
		random-1.1_1 \
		regex-base-0.93.2_1 \
		regex-tdfa-1.2.3.2 \
		regex-tdfa-text-1.0.0.3 \
		resourcet-1.2.2 \
		safe-0.3.17 \
		scientific-0.3.6.2 \
		split-0.2.3.3_1 \
		streaming-commons-0.2.1.1 \
		tagged-0.8.6_1 \
		th-abstraction-0.3.1.0 \
		time-compat-1.9.2.2_1 \
		transformers-compat-0.6.5 \
		typed-process-0.2.6.0 \
		unliftio-core-0.1.2.0_2 \
		unordered-containers-0.2.10.0_1 \
		uuid-types-1.0.3_2 \
		vector-0.12.0.3_2 \
		vector-algorithms-0.8.0.1_2 \
		xdg-basedir-0.2.2 \
		xml-conduit-1.8.0.1 \
		xml-types-0.3.6 \
		zlib-0.6.2

.include <bsd.port.mk>
