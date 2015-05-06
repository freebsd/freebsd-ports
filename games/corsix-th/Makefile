# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	corsixth
PORTVERSION=	0.40
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source clone of Theme Hospital

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USES=		cmake compiler:c++11-lang dos2unix pkgconfig
USE_SDL=	mixer
DOS2UNIX_FILES=	CMake/FindFFmpeg.cmake \
		CorsixTH/CMakeLists.txt \
		CorsixTH/Src/iso_fs.cpp

USE_GITHUB=	yes
GH_ACCOUNT=	CorsixTH
GH_PROJECT=	CorsixTH

OPTIONS_DEFINE=	LUAJIT MOVIES
OPTIONS_DEFAULT=	LUAJIT MOVIES
LUAJIT_DESC=	Use LUAJIT compiler
MOVIES_DESC=	Play in-game movies

MOVIES_CMAKE_ON=	-DWITH_MOVIES=ON
MOVIES_CMAKE_OFF=	-DWITH_MOVIES=OFF
MOVIES_LIB_DEPENDS=	libswresample.so:${PORTSDIR}/multimedia/ffmpeg
LUAJIT_CMAKE_ON=	-DWITH_LUAJIT=ON
LUAJIT_CMAKE_OFF=	-DWITH_LUAJIT=OFF
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
LUAJIT_USES_OFF=	lua:51

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
