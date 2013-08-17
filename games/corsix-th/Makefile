# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	corsixth
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	corsix-th
DISTNAME=	CorsixTH-${DISTVERSION}-Source

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source clone of Theme Hospital

LICENSE=	MIT

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

USES=		cmake
USE_LUA=	yes
USE_SDL=	mixer
USE_DOS2UNIX=	CMake/FindFFmpeg.cmake \
		CorsixTH/CMakeLists.txt

OPTIONS_DEFINE=	MOVIES
OPTIONS_DEFAULT=	MOVIES
MOVIES_DESC=	Play in-game movies

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOVIES}
CMAKE_ARGS+=	-DWITH_MOVIES=ON
LIB_DEPENDS+=	swresample1:${PORTSDIR}/multimedia/ffmpeg1
# partly copied from editors/libreoffice
.if ${ARCH} == "i386"
.if exists(/usr/bin/clang) && ${OSVERSION} > 900014
CC=		/usr/bin/clang
CPP=		/usr/bin/clang-cpp
CXX=		/usr/bin/clang++
.else
USE_GCC=	yes
.endif
.endif
.else
CMAKE_ARGS+=	-DWITH_MOVIES=OFF
.endif

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
