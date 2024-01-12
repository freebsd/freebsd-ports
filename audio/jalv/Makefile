PORTNAME=	jalv
DISTVERSION=	1.6.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple but fully featured LV2 plugin host for Jack
WWW=		https://drobilla.net/software/jalv

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libjack.so:audio/jack \
		libsord-0.so:devel/sord \
		libserd-0.so:devel/serd \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gnome pkgconfig meson qmake:no_configure,no_env \
		qt:5 tar:xz
USE_QT=		core gui widgets buildtools:build
USE_GNOME=	atk atkmm cairo cairomm pango pangomm libsigc++20 \
		gdkpixbuf2 glib20 glibmm  gtk20 gtk30 gtkmm24
MESON_ARGS=	-Dportaudio=disabled

CXXFLAGS+=	-fPIC

.include <bsd.port.mk>
