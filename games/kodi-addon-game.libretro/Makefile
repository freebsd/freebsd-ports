PORTNAME=	game.libretro
PORTVERSION=	22.2.5.20260320
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	games

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Libretro compatibility layer for the Kodi Game API
WWW=		https://github.com/kodi-game/game.libretro

LICENSE=	GPLv2+

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml

USES=		cmake localbase compiler:c++14-lang kodi
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game:DEFAULT \
		libretro:libretro \
		RetroAchievements:rcheevos
GH_PROJECT=	game.libretro:DEFAULT \
		libretro-common:libretro \
		rcheevos:rcheevos
# See: https://github.com/kodi-game/game.libretro/tree/Piers/depends/common
GH_TAGNAME=	d7be5fa3c7ef3cf727bc36ff65f1a067a198b45c:DEFAULT \
		55ca668901e72eb885976c8c839e6903ecbb119d:libretro \
		v9.2.0:rcheevos

CMAKE_ON=	ENABLE_INTERNAL_LIBRETROCOMMON \
		ENABLE_INTERNAL_RCHEEVOS

CMAKE_ARGS=	-DLIBRETROCOMMON_URL="${DISTDIR}/${DISTFILE_libretro}" \
		-DRCHEEVOS_URL="${DISTDIR}/${DISTFILE_rcheevos}"

post-extract:
	@${MKDIR} ${WRKDIR}/.build
	@${MKDIR} ${STAGEDIR}${WRKDIR}
	@${LN} -sf ${WRKDIR}/.build ${STAGEDIR}${WRKDIR}/

post-build:
	@${RM} -rf ${STAGEDIR}${WRKDIRPREFIX}

.include <bsd.port.mk>
