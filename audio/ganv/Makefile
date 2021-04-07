PORTNAME=	ganv
PORTVERSION=	1.8.0
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive Gtk canvas widget for audio topologies representation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcgraph.so:graphics/graphviz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gettext-runtime gnome pkgconfig waf tar:bz2
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf2 glib20 glibmm gtk20 gtkmm24 libsigc++20 pango pangomm
USE_LDCONFIG=	yes

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/ganv_bench lib/libganv-1.so.${PORTVERSION}

.include <bsd.port.mk>
