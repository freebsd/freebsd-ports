PORTNAME=	game.libretro.picodrive
PORTVERSION=	1.98.0.26
DISTVERSIONSUFFIX=	-Matrix
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sega - MS/MD/CD/32X (PicoDrive)

LICENSE=	GPLv2+

LIBRETRO_PORT=	libretro-picodrive

RUN_DEPENDS=	kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro \
		${LIBRETRO_PORT}>=0:games/${LIBRETRO_PORT}

NO_ARCH=	yes

USES=		kodi

USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game

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
