# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-generic-slider
PORTVERSION=	0.0.20100827
PORTREVISION=	7
CATEGORIES=	deskutils
MASTER_SITES=	LOCAL/ehaupt/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Slider plugin to adjust and/or monitor any numeric variable

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-runtime pkgconfig xfce
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_XFCE=	libgui panel

CFLAGS+=	`pkg-config --cflags libxfce4panel-1.0 libxfcegui4-1.0`
LDFLAGS+=	`pkg-config --libs libxfce4panel-1.0 libxfcegui4-1.0`

post-patch:
	@${REINPLACE_CMD} -e \
		"s|@PLUGINDIR@|${PREFIX}/lib/xfce4/xfce4/panel-plugins|" \
			${WRKSRC}/generic-slider.desktop

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/generic-slider.c \
		-o ${WRKSRC}/generic-slider.o
	${CC} ${LDFLAGS} ${WRKSRC}/generic-slider.o \
		-o ${WRKSRC}/xfce4-generic-slider-plugin

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xfce4/panel-plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xfce4/xfce4/panel-plugins
	${INSTALL_DATA} ${WRKSRC}/generic-slider.desktop \
		${STAGEDIR}${PREFIX}/share/xfce4/panel-plugins
	${INSTALL_PROGRAM} ${WRKSRC}/xfce4-generic-slider-plugin \
		${STAGEDIR}${PREFIX}/lib/xfce4/xfce4/panel-plugins

.include <bsd.port.mk>
