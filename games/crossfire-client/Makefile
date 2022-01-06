# Created by: Andreas Klemm <andreas@klemm.gtn.com>

PORTNAME=	crossfire-client
PORTVERSION=	1.75.2
CATEGORIES=	games
MASTER_SITES=	SF/crossfire/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Cooperative multiplayer graphical RPG and adventure game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake gnome perl5 pkgconfig sdl
USE_GNOME=	gtk20
USE_PERL5=	build
USE_SDL=	sdl image mixer

CMAKE_ARGS=	-DLUA=OFF -DMETASERVER2=ON -DSOUND=ON

.include <bsd.port.mk>
