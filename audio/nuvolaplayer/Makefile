# $FreeBSD$

PORTNAME=	nuvolaplayer
PORTVERSION=	3.0.4
PORTREVISION=	2
CATEGORIES=	audio www

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Cloud music integration for your desktop

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libdioritegtk-0.2.so:x11-toolkits/diorite \
		libjson-glib-1.0.so:devel/json-glib \
		libnotify.so:devel/libnotify \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
BUILD_DEPENDS=	valac:lang/vala
RUN_DEPENDS=	${PORTNAME}-all-services>=0:www/${PORTNAME}-all-services

USE_GITHUB=	yes
GH_ACCOUNT=	tiliado

USES=		compiler:c11 gnome libarchive pkgconfig waf
USE_GNOME=	glib20 gtk30
USE_XORG=	x11
# src/nuvolakit-runner/components/keybindings/XKeyGrabber.c:128:2: error: non-void function 'nuvola_xkey_grabber_construct' should return a value [-Wreturn-type]
CFLAGS+=	-Wno-return-type
CONFIGURE_ARGS=	--platform=LINUX
MAKE_ARGS=	--no-system-hooks
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

.ifdef(WITH_DEBUG)
CONFIGURE_ARGS+=--debug
.else
CONFIGURE_ARGS+=--no-debug
.endif

DATADIR=	${PREFIX}/share/${PORTNAME}3

OPTIONS_DEFINE=	MPG123
OPTIONS_DEFAULT=MPG123

MPG123_DESC=	HTML5 audio support via mpg123

MPG123_USE=	GSTREAMER1=good,mpg123

pre-configure:
	${REINPLACE_CMD} -e 's/Linux desktop/desktop/' \
		${WRKSRC}/wscript \
		${WRKSRC}/data/${PORTNAME}3.appdata.xml

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}3/*

.include <bsd.port.mk>
