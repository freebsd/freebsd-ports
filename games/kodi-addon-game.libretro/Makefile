PORTNAME=	game.libretro
PORTVERSION=	21.0.6
DISTVERSIONSUFFIX=	-Omega
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
GH_TAGNAME=	2cb1ed77d3a31d73301447c60f600eaebccd2f07:DEFAULT \
		50c15a88eb741cbe675743a282d8cc4c89421e3f:libretro \
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
