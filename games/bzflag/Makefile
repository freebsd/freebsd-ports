# $FreeBSD$

PORTNAME=	bzflag
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multiplayer 3D tank battle game

LICENSE=	LGPL21

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GL=		glew
USE_SDL=	sdl
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--enable-ares-build
CPPFLAGS+=	-I ${LOCALBASE}/include

DESKTOP_ENTRIES=	"BZFlag" "Battle enemy tanks" \
			"${DATADIR}/bzflag-256x256.png" \
			"bzflag" "Game;ActionGame;" false

MAN5=	bzw.5
MAN6=	bzadmin.6 bzflag.6 bzfs.6

.include <bsd.port.mk>
