PORTNAME=	game.libretro.picodrive
PORTVERSION=	2.05.0.57.20260330
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	games

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sega - MS/MD/CD/32X (PicoDrive)
WWW=		https://github.com/kodi-game/game.libretro.picodrive

LICENSE=	GPLv2+

LIBRETRO_PORT=	libretro-picodrive

RUN_DEPENDS=	kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro \
		${LIBRETRO_PORT}>=0:games/${LIBRETRO_PORT}

NO_ARCH=	yes

USES=		kodi
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game
GH_TAGNAME=	ab4850fdd2625230b036312a9b0b1d3e58c8e561

do-build:
	@${MKDIR} ${WRKSRC}/lib
	@LIBRARY_FILENAME_FULL=`${MAKE} -C ../${LIBRETRO_PORT} -V PLIST_FILES | ${SED} 's| .*||g'` && \
	LIBRARY_FILENAME=`basename "$${LIBRARY_FILENAME_FULL}"` && \
	${LN} -sf "${LOCALBASE}/$${LIBRARY_FILENAME_FULL}" ${WRKSRC}/lib/ && \
	${REINPLACE_CMD} -e 's|@PLATFORM@|freebsd|g' \
		-e "s|@LIBRARY_FILENAME@|$${LIBRARY_FILENAME}|g" \
		${WRKSRC}/${PORTNAME}/addon.xml.in
	@${MV} ${WRKSRC}/${PORTNAME}/addon.xml.in ${WRKSRC}/${PORTNAME}/addon.xml
	@${RM} -f ${WRKSRC}/${PORTNAME}/addon.xml.in.bak

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/kodi/addons/${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/kodi/addons
	@(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} * ${STAGEDIR}${PREFIX}/lib/kodi/addons/${PORTNAME})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/share/kodi/addons)

.include <bsd.port.mk>
