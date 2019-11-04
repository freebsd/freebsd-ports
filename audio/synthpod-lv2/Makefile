# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	synthpod
PORTVERSION=	g20190407
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Nonlinear LV2 Plugin Container

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		meson compiler:c++11-lib pkgconfig localbase
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers
GH_TAGNAME=	01aad91
USE_CXXSTD=	c++11

MESON_ARGS=	-Duse-alsa=false -Duse-qt4=false

OPTIONS_DEFINE=		JACK DUMMY
OPTIONS_DEFAULT=	JACK X11
OPTIONS_GROUP=		UI
OPTIONS_GROUP_UI=	X11 GTK2 GTK3 QT
OPTIONS_SUB=		yes

DUMMY_DESC=		Build DUMMY standalone host
DUMMY_MESON_OFF=	-Duse-dummy=false
DUMMY_LIB_DEPENDS=	libuv.so:devel/libuv

GTK2_DESC=		Build GTK-2 sandbox
GTK2_MESON_OFF=		-Duse-gtk2=false
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK2_USES=		gl gnome xorg
GTK2_USE=		XORG=x11,xcb,xext GL=gl,glu GNOME=glib20,gtk20,gdkpixbuf2,atk,cairo,pango gettext-runtime

GTK3_DESC=		Build GTK-3 sandbox
GTK3_MESON_OFF=		-Duse-gtk3=false
GTK3_USES=		gl gnome xorg
GTK3_USE=		XORG=x11,xcb,xext GL=glu GNOME=glib20,gtk30,gdkpixbuf2,atk,cairo,pango gettext-runtime

JACK_DESC=		Build JACK standalone host
JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libuv.so:devel/libuv
JACK_MESON_OFF=		-Duse-jack=false

QT_DESC=		Build Qt-5 sandbox
QT_USES=		qt:5
QT_MESON_OFF=		-Duse-qt5=false
QT_USE=			QT=core,widgets

X11_DESC=		Build X11 sandbox
X11_MESON_OFF=		-Duse-x11=false
X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
X11_USES=		gnome
X11_USE=		XORG=xcb GNOME=cairo

.include <bsd.port.mk>
