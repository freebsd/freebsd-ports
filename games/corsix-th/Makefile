# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	corsixth
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	corsix-th
DISTNAME=	CorsixTH-${DISTVERSION}-Source

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source clone of Theme Hospital

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USES=		cmake compiler:c++11-lang pkgconfig
USE_LUA=	yes
USE_SDL=	mixer
USE_DOS2UNIX=	CMake/FindFFmpeg.cmake \
		CorsixTH/CMakeLists.txt \
		CorsixTH/Src/iso_fs.cpp

OPTIONS_DEFINE=	MOVIES
OPTIONS_DEFAULT=	MOVIES
MOVIES_DESC=	Play in-game movies

MOVIES_CMAKE_ON=	-DWITH_MOVIES=ON
MOVIES_CMAKE_OFF=	-DWITH_MOVIES=OFF
MOVIES_LIB_DEPENDS=	libswresample.so:${PORTSDIR}/multimedia/ffmpeg

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOVIES} && ${OSVERSION} < 900014
FAVORITE_COMPILER=	gcc
.endif

post-patch:
# Allow the game to find its resources without wrapper scripts
	@${REINPLACE_CMD} -e \
		'/return loadfile/s,name,\\"${DATADIR}/\\" .. &,' \
			${WRKSRC}/CorsixTH/Src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CorsixTH/CorsixTH ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CorsixTH/CorsixTH.lua ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/CorsixTH && ${COPYTREE_SHARE} "Bitmap Levels Lua" \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
