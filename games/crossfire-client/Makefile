# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	crossfire-client
PORTVERSION=	1.71.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/crossfire/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Cooperative multiplayer graphical RPG and adventure game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		pkgconfig tar:bzip2
USE_GL=		glut
USE_GNOME=	gtk20
USE_SDL=	sdl image mixer

post-install:
	${CP} ${WRKSRC}/pixmaps/48x48.png ${WRKSRC}/pixmaps/crossfire-client.png
	${INSTALL_DATA} ${WRKSRC}/gtk-v2/crossfire-client.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/pixmaps/crossfire-client.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
