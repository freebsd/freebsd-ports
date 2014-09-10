# $FreeBSD$

PORTNAME=	bzflag
PORTVERSION=	2.4.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multiplayer 3D tank battle game

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USES=		libtool tar:bzip2
USE_GL=		glew
USE_SDL=	sdl

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--enable-ares-build
CPPFLAGS+=	-I ${LOCALBASE}/include

DESKTOP_ENTRIES=	"BZFlag" "Battle enemy tanks" \
			"${DATADIR}/bzflag-256x256.png" \
			"bzflag" "Game;ActionGame;" false

.include <bsd.port.mk>
