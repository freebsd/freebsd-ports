# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensurge
PORTVERSION=	0.1.r${SVN_REV}
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.ime.usp.br/~alemart/opensurge_nightly/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/
DISTFILES=	${PORTNAME}-src-build${SVN_REV}${EXTRACT_SUFX} \
		${PORTNAME}-mods-${MODS_VER}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game based on the Sonic the Hedgehog universe

LICENSE=	GPLv2+ CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/licenses/GPLv2.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/licenses/CC-BY-SA-3.0.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libaldmb.a:audio/dumb-allegro \
		${LOCALBASE}/include/alfont.h:x11-fonts/alfont \
		alureplay:audio/alure
LIB_DEPENDS=	liballeg.so:devel/allegro \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis
RUN_DEPENDS=	${LOCALBASE}/lib/libaldmb.a:audio/dumb-allegro

WRKSRC=		${WRKDIR}/${PORTNAME}-src-build${SVN_REV}

USES=		cmake dos2unix openal:soft
DOS2UNIX_GLOB=	*.bg *.brk *.grp  *.inc *.lev *.lng  *.obj *.qst *.spr *.txt
USE_GCC=	yes

PORTDOCS=	readme.html
PORTDATA=	*
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-deinstall pkg-message

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 32x32 48x48 64x64 72x72 96x96 128x128 256x256

DESKTOP_ENTRIES="Open Surge" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

.include "Makefile.svn_rev"

post-extract-script:
	@(cd ${WRKDIR}/opensurge-mods && ${COPYTREE_SHARE} . ${WRKSRC})

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/opensurge|${DATADIR}|' \
		-e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/core/global.h
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/core/osspec.c

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|; \
		s|/usr/bin|${PREFIX}/bin|; \
		s|license.txt readme.html||; \
		s|licenses||' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' '/Copying executable to/,+2d' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	@${INSTALL_DATA} ${WRKSRC}/src/misc/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
