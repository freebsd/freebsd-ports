# New ports collection makefile for:	crossfire-client
# Date created:		1996-10-27
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	crossfire-client
PORTVERSION=	1.70.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/crossfire/crossfire-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	A cooperative multiplayer graphical RPG and adventure game

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20 libglade2
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-alsa

MAN6=	crossfire-client-gtk2.6

post-patch:
	${REINPLACE_CMD} -e '/#include <curl\/types.h>/d' \
		${WRKSRC}/common/metaserver.c
	${REINPLACE_CMD} -e "/mandir='${datarootdir}\/man'/d" \
		${WRKSRC}/configure

post-install:
	${CP} ${WRKSRC}/pixmaps/48x48.png ${WRKSRC}/pixmaps/crossfire-client.png
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gtk-v2/crossfire-client.desktop \
		${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/crossfire-client.png \
		${PREFIX}/share/pixmaps

.include <bsd.port.mk>
