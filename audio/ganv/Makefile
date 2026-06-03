PORTNAME=	ganv
DISTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive Gtk canvas widget for audio topologies representation
WWW=		https://drobilla.net/software/ganv.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcgraph.so:graphics/graphviz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gettext gnome localbase:ldflags meson pkgconfig tar:xz
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf glib20 glibmm gtk20 gtkmm24 introspection:build libsigc++20 pango pangomm
USE_LDCONFIG=	yes

.include <bsd.port.mk>
