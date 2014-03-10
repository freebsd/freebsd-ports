# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	openjazz
PORTVERSION=	20120819
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://alister.eu/jazz/oj/ \
		LOCAL/martymac
DISTNAME=	OpenJazz-src-190812

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free re-implementation of the Jazz Jackrabbit(tm) game engine

LICENSE=	GPLv2

WRKSRC=	${WRKDIR}/${PORTNAME}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=	dos2unix gmake zip:infozip
DOS2UNIX_REGEX=	.*\.(h|cpp)
ALL_TARGET=	OpenJazz
USE_XORG=	x11 xext xrandr xrender xau xdmcp
USE_SDL=	sdl

CPPFLAGS+=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` \
		-DDATAPATH=\\\"${DATADIR}/\\\" -DHOMEDIR
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} `${SDL_CONFIG} --libs`

SUB_FILES=	pkg-message

pre-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/openjazz.000 ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/OpenJazz ${STAGEDIR}${PREFIX}/bin/openjazz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openjazz

.include <bsd.port.mk>
