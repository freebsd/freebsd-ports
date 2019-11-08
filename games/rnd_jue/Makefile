# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rnd_jue
PORTVERSION=	3.3.0.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/:game \
		SF/nemysisfreebsdp/${CATEGORIES}/rocksndiamonds/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:game \
		rocksndiamonds-3.3.1.0${EXTRACT_SUFX}:game \
		${LEVELS_BD_FANS:S/$/.zip/} \
		Tutorial_Alpha.zip \
		${PORTNAME}_icons.tar.gz
DIST_SUBDIR=	rocksndiamonds
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		rocksndiamonds-3.3.1.0${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Colorful Boulderdash'n'Emerald Mine'n'Sokoban'n'Stuff jue

LICENSE=	GPLv2

LIB_DEPENDS+=	libsmpeg.so:multimedia/smpeg
EXTRACT_DEPENDS+=${UNZIP_CMD}:archivers/unzip

USES=		gmake gnome sdl
USE_SDL=	image mixer net sdl
MAKE_ARGS=	CC="${CC}" MAKE="${MAKE_CMD}" OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" \
		X11_PATH="${LOCALBASE}"
ALL_TARGET=	sdl

SUB_FILES=	pkg-message

LEVELS_BD_FANS=	JuergenBonhagen rnd_the_h_world Walpurgis_Collection

PORTDOCS=	*
PORTDATA=	*

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="R'n'D jue" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

post-extract-script:
	@(cd ${WRKDIR}/rocksndiamonds* && ${COPYTREE_SHARE} levels ${WRKSRC})
.for l in ${LEVELS_BD_FANS:S/$/.zip/}
	@${UNZIP_CMD} -qo -d ${WRKSRC}/levels ${_DISTDIR}/${l}
.endfor
	@${UNZIP_CMD} -qo -d ${WRKSRC}/levels/Tutorials \
		${_DISTDIR}/Tutorial_Alpha.zip
	@(cd ${WRKSRC}/levels/Tutorials && ${MV} \
		"Tutorial Alpha" rnd_tutorial_alpha)

	@(cd ${WRKSRC}/levels/"Walpurgis Collection" && \
		${RM} -r "Walpurgis Gardens" "Walpurgis World")
	@(cd ${WRKSRC}/levels/rnd_the_h_world && ${RM} -r hwld_dceos)
	@${RM} ${WRKDIR}/${PORTNAME}/Readme.txt
	@${RM} ${WRKSRC}/levels/Readme.txt

post-patch:
	@${REINPLACE_CMD} \
		-e 's|sdl-config|$${SDL_CONFIG}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} \
		-e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/src/libgame/sound.c
	@${REINPLACE_CMD} \
		-e 's|machine/joystick.h|sys/joystick.h|' \
		${WRKSRC}/src/libgame/joystick.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for dir in graphics levels music sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR})
.endfor
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "CREDITS ChangeLog docs/elements" \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
