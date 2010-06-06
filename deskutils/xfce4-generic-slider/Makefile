# New ports collection makefile for:	xfce4-generic-slider
# Date created:				04 Jun 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-generic-slider
PORTVERSION=	0.0.20100604
CATEGORIES=	deskutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A slider plugin to adjust and/or monitor any numeric variable

USE_XFCE=	panel
USE_GNOME=	pkgconfig

CFLAGS+=	`pkg-config --cflags libxfce4panel-1.0`
LDFLAGS+=	`pkg-config --libs libxfce4panel-1.0`

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
	${MKDIR} ${PREFIX}/share/xfce4/panel-plugins
	${MKDIR} ${PREFIX}/lib/xfce4/xfce4/panel-plugins
	${INSTALL_DATA} ${WRKSRC}/generic-slider.desktop \
		${PREFIX}/share/xfce4/panel-plugins
	${INSTALL_PROGRAM} ${WRKSRC}/xfce4-generic-slider-plugin \
		${PREFIX}/lib/xfce4/xfce4/panel-plugins

.include <bsd.port.mk>
