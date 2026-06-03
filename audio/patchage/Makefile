PORTNAME=	patchage
DISTVERSION=	1.0.10
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular patch bay for Jack
WWW=		https://drobilla.net/software/patchage.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional/optional.hpp:devel/boost-libs \
		raul>0:audio/raul
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libboost_date_time.so:devel/boost-libs \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libganv-1.so:audio/ganv \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++14-lang gettext gnome localbase meson pkgconfig python:build tar:xz
USE_GNOME=	atk cairo cairomm glib20 glibmm gdkpixbuf gtk20 gtkmm24 libsigc++20 pango pangomm
MESON_ARGS=	-Djack=disabled

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
