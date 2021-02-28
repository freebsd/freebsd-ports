# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	game.libretro.genplus
PORTVERSION=	1.7.4.15
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	games

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sega - MS/GG/MD/CD (Genesis Plus GX)

LICENSE=	GPGX
LICENSE_NAME=	GPGX
LICENSE_FILE=	${WRKSRC}/depends/common/genplus/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro

USES=		cmake:noninja gmake kodi
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:genplus
GH_PROJECT=	Genesis-Plus-GX:genplus
# Keep in sync with: depends/common/genplus/genplus.txt
GH_TAGNAME=	0164eb9730c0803674a54a3694633a56f4801661:genplus

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DGENPLUS_LIB=depends/common/genplus/genesis_plus_gx_libretro.so

post-extract:
	@${MV} ${WRKSRC_genplus}/* ${WRKSRC}/depends/common/genplus/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(GENPLUS_LIB.*|add_subdirectory(depends/common/genplus)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
