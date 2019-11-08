# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	corsixth
PORTVERSION=	0.63
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source clone of Theme Hospital

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	${LUA_MODLIBDIR}/lfs.so:devel/luafilesystem \
		${LUA_MODLIBDIR}/lpeg.so:devel/lua-lpeg

USES=		cmake:insource compiler:c++11-lib desktop-file-utils dos2unix \
		iconv lua pkgconfig sdl
USE_SDL=	mixer2
DOS2UNIX_FILES=	CMake/FindFFmpeg.cmake \
		CorsixTH/CMakeLists.txt \
		CorsixTH/Src/iso_fs.cpp
CMAKE_ARGS=	-DWITH_LUAJIT=OFF
CFLAGS+=	-I${ICONV_PREFIX}/include
DATADIR=	${PREFIX}/share/corsix-th

DESKTOP_ENTRIES=	"CorsixTH" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/corsix-th.png" \
			"${PREFIX}/bin/corsix-th" \
			"Game;" \
			""

USE_GITHUB=	yes
GH_ACCOUNT=	CorsixTH
GH_PROJECT=	CorsixTH

OPTIONS_DEFINE=	MOVIES
OPTIONS_DEFAULT=	MOVIES
MOVIES_DESC=	Play in-game movies

MOVIES_CMAKE_ON=	-DWITH_MOVIES=ON
MOVIES_CMAKE_OFF=	-DWITH_MOVIES=OFF
MOVIES_LIB_DEPENDS=	libswresample.so:multimedia/ffmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CorsixTH/corsix-th ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CorsixTH/CorsixTH.lua ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/CorsixTH && ${COPYTREE_SHARE} "Bitmap Levels Lua" \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LDocGen/output/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/corsix-th.png

.include <bsd.port.mk>
