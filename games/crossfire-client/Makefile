# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	crossfire-client
PORTVERSION=	1.73.0
CATEGORIES=	games
MASTER_SITES=	SF/crossfire/${PORTNAME}/${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Cooperative multiplayer graphical RPG and adventure game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake gnome perl5 pkgconfig sdl tar:bzip2
USE_PERL5=	build
USE_GNOME=	gtk20
USE_SDL=	sdl image mixer
INSTALLS_ICONS=	YES

CMAKE_ARGS=	-DLUA=OFF -DMETASERVER2=ON -DOPENGL=OFF -DSDL=ON -DSOUND=ON

.include <bsd.port.mk>
