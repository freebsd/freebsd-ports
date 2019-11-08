# Created by: edwin@mavetju.org
# $FreeBSD$

PORTNAME=	einstein
PORTVERSION=	2.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://games.flowix.com/files/einstein/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Remake of old DOS game Sherlock, which was inspired by Albert Einstein's puzzle

LICENSE=	GPLv2+ # (now dead) website mentions GPL

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		sdl
USE_SDL=	sdl ttf mixer
USE_CXXSTD=	c++98
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/einstein

.include <bsd.port.mk>
