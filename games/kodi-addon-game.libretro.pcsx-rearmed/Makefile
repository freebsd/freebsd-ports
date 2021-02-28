# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	game.libretro.pcsx-rearmed
PORTVERSION=	22.0.0.19
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	games

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sony - PlayStation (PCSX ReARMed)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/depends/common/pcsx-rearmed/COPYING

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro

USES=		cmake:noninja gmake kodi
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:pcsx_rearmed
GH_PROJECT=	pcsx_rearmed:pcsx_rearmed
# Keep in sync with: depends/common/pcsx-rearmed/pcsx-rearmed.txt
GH_TAGNAME=	54686ee7ccbba7220aaf69892ad3d77515478776:pcsx_rearmed

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DPCSX-REARMED_LIB=depends/common/pcsx-rearmed/pcsx_rearmed_libretro.so

post-extract:
	@${MV} ${WRKSRC_pcsx_rearmed}/* ${WRKSRC}/depends/common/pcsx-rearmed/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(PCSX-REARMED_LIB.*|add_subdirectory(depends/common/pcsx-rearmed)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
