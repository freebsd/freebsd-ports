# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	synthpod
PORTVERSION=	g20170810
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@rawbw.com
COMMENT=	Lightweight Nonlinear LV2 Plugin Container

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		cmake compiler:c++11-lib pkgconfig localbase
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers
GH_TAGNAME=	07cae54
USE_CXXSTD=	c++11

CMAKE_ARGS=	-DBUILD_ALSA="OFF"

OPTIONS_DEFINE=	JACK DUMMY DOT
OPTIONS_DEFAULT=JACK X11 SHOW KX
OPTIONS_GROUP=	UI
OPTIONS_GROUP_UI=	X11 GTK2 GTK3 QT4 QT5 SHOW KX
OPTIONS_SUB=	yes

DUMMY_DESC=	Build DUMMY standalone host
DOT_DESC=	Build Dot exporter
KX_DESC=	Build external-ui sandbox
JACK_DESC=	Build JACK standalone host
X11_DESC=	Build X11 sandbox
GTK2_DESC=	Build GTK-2 sandbox
GTK3_DESC=	Build GTK-3 sandbox
QT4_DESC=	Build Qt-4 sandbox
QT5_DESC=	Build Qt-5 sandbox
SHOW_DESC=	Build show-iface sandbox

DOT_CMAKE_ON=	-DBUILD_DOT="ON"
DUMMY_CMAKE_ON=	-DBUILD_DUMMY="ON"
DUMMY_LIB_DEPENDS=	libuv.so:devel/libuv
GTK2_CMAKE_ON=		-DBUILD_UI="ON" -DBUILD_SANDBOX_GTK2="ON"
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK2_USE=	XORG=x11,xcb,xext GL=gl,glu GNOME=glib20,gtk20,gdkpixbuf2,atk,cairo,pango gettext-runtime
GTK3_CMAKE_ON=	-DBUILD_UI="ON" -DBUILD_SANDBOX_GTK3="ON"
GTK3_USE=	XORG=x11,xcb,xext GL=glu GNOME=glib20,gtk30,gdkpixbuf2,atk,cairo,pango gettext-runtime
JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libuv.so:devel/libuv
JACK_CMAKE_OFF=	-DBUILD_JACK="OFF"
KX_CMAKE_ON=	-DBUILD_UI="ON" -DBUILD_SANDBOX_KX="ON"
KX_USE=		XORG=x11,xcb,xext GL=glu
QT4_CMAKE_ON=	-DBUILD_UI="ON" -DBUILD_SANDBOX_QT4="ON"
QT4_USE=	XORG=x11,xcb,xext GL=glu QT4=corelib,gui
QT5_BROKEN=	Build fails: https://github.com/OpenMusicKontrollers/synthpod/issues/10
QT5_CMAKE_ON=	-DBUILD_UI="ON" -DBUILD_SANDBOX_QT5="ON"
QT5_USE=	XORG=x11,xcb,xext GL=glu QT5=core,gui
SHOW_USE=	XORG=x11,xcb,xext GL=glu
SHOW_CMAKE_ON=	-DBUILD_UI="ON" -DBUILD_SANDBOX_SHOW="ON"
X11_CMAKE_ON=	-DBUILD_UI="ON" -DBUILD_SANDBOX_X11="ON"
X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
X11_USE=	XORG=x11,xcb,xext GL=gl,glu

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11} || ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3} || ${PORT_OPTIONS:MQT4} || ${PORT_OPTIONS:MQT5} || ${PORT_OPTIONS:MSHOW} || ${PORT_OPTIONS:MKX}
PLIST_SUB+=	UI=""
.else
PLIST_SUB+=	UI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/bin/CMakeLists.txt

.include <bsd.port.mk>
