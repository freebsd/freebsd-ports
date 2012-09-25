# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	corsixth
PORTVERSION=	0.10
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	corsix-th
DISTNAME=	CorsixTH-${DISTVERSION}-Sourze

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source clone of Theme Hospital

LICENSE=	MIT

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_CMAKE=	yes
USE_LUA=	yes
USE_SDL=	mixer
WRKSRC=		${WRKDIR}

post-patch:
# Allow the game to find its resources without wrapper scripts
	@${REINPLACE_CMD} -e \
		'/return loadfile/s,name,\\"${DATADIR}/\\" .. &,' \
			${WRKSRC}/CorsixTH/Src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CorsixTH/CorsixTH ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CorsixTH/CorsixTH.lua ${DATADIR}
	cd ${WRKSRC}/CorsixTH && ${COPYTREE_SHARE} "Bitmap Levels Lua" \
		${DATADIR}

.include <bsd.port.mk>
