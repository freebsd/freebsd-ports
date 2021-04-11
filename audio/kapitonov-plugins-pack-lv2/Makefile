PORTNAME=	kapitonov-plugins-pack
DISTVERSION=	1.2.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Kapitonov LV2 Plugins Pack (KPP)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		faust:audio/faust \
		${LOCALBASE}/include/boost/circular_buffer.hpp:devel/boost-libs
LIB_DEPENDS=	libzita-convolver.so:audio/zita-convolver \
		libzita-resampler.so:audio/zita-resampler \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-util.so:x11/xcb-util

USES=		compiler:c11 gnome localbase:ldflags meson pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	olegkapitonov
GH_PROJECT=	Kapitonov-Plugins-Pack

MESON_ARGS=	-Dladspa=disabled

.include <bsd.port.mk>
