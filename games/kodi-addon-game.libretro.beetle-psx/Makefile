# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	game.libretro.beetle-psx
PORTVERSION=	0.9.44.22
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	games

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sony - PlayStation (Beetle PSX)

LICENSE=	GPLv2+

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro

USES=		cmake:noninja gmake kodi localbase
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:beetle_psx
GH_PROJECT=	beetle-psx-libretro:beetle_psx
# Keep in sync with: depends/common/beetle-psx/beetle-psx.txt
GH_TAGNAME=	e1836bde1b250d41c6f91c2b6f06444d989f1138:beetle_psx

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DBEETLE-PSX_LIB=depends/common/beetle-psx/mednafen_psx_libretro.so

post-extract:
	@${MV} ${WRKSRC_beetle_psx}/* ${WRKSRC}/depends/common/beetle-psx/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(BEETLE-PSX_LIB.*|add_subdirectory(depends/common/beetle-psx)|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|defined(BSD)|!defined(CLOCK_REALTIME)|g' \
		${WRKSRC}/depends/common/beetle-psx/libretro-common/rthreads/rthreads.c

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
