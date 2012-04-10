# New ports collection makefile for:	crossfire-client
# Date created:		1996-10-27
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	crossfire-client
PORTVERSION=	1.60.0
CATEGORIES=	games
MASTER_SITES=	SF/crossfire/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	A cooperative multiplayer graphical RPG and adventure game

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-alsa

MAN6=	crossfire-client-gtk2.6

post-patch:
	${REINPLACE_CMD} -e '/#include <curl\/types.h>/d' \
		${WRKSRC}/common/metaserver.c

.include <bsd.port.mk>
