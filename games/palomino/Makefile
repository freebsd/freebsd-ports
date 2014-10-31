# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	palomino
PORTVERSION=	20131231
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.palomino3d.org/software/${PORTNAME}/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.txz \
		${PORTNAME}_data_misc_${MISC_VER}${EXTRACT_SUFX} \
		${PORTNAME}_data_models_${MODELS_VER}${EXTRACT_SUFX} \
		${PORTNAME}_data_sounds_${SOUNDS_VER}${EXTRACT_SUFX} \
		${PORTNAME}_data_terrain_${TERRAIN_VER}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Action flight simulation computer program using OSG

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GNU_GPL_2.txt

LIB_DEPENDS=	libosg.so:${PORTSDIR}/graphics/osg

USES=		alias cmake lua:51 tar:xz
USE_GL=		gl

MISC_VER=	20091027
MODELS_VER=	20090615
SOUNDS_VER=	20080704
TERRAIN_VER=	20080206

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	GUI PLIB SDL
OPTIONS_DEFAULT=	GUI SDL

PLIB_DESC=	Enable sound support through plib
GUI_DESC=	Enable FLTK GUI

OPTIONS_SUB=	yes

GUI_LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk
PLIB_BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

PORTDOCS=	*

DESKTOP_ENTRIES=	"Palomino" "" "${PORTNAME}" \
			"${PORTNAME}" "Game;ArcadeGame;" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl mixer
.endif

post-patch:
	@${FIND} ${WRKSRC}/CMakeModules -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g'
	@${REINPLACE_CMD} -e '/ rt / d' ${WRKSRC}/CMakeModules/libraries.cmake
	@${REINPLACE_CMD} -e '/COMMAND/ s|lua|${LUA_CMD}|' \
		${WRKSRC}/build/lua_bind/CMakeLists.txt
	@${REINPLACE_CMD} -e '/FIND_PACKAGE(/ s|)| REQUIRED)|' \
		${WRKSRC}/CMakeModules/libraries.cmake
	@${REINPLACE_CMD} -e '/COMPILE_WITH_OSSIM/ d' ${WRKSRC}/CMakeLists.txt

# Please look MOVED devel/linux-js||2013-06-04
	@${REINPLACE_CMD} -e '/COMPILE_WITH_LINUX_JOYSTICK/ d' ${WRKSRC}/CMakeLists.txt

.if ! ${PORT_OPTIONS:MSDL}
	@${REINPLACE_CMD} -e '/COMPILE_WITH_SDL/ d' ${WRKSRC}/CMakeLists.txt
.endif

.if ! ${PORT_OPTIONS:MPLIB}
	@${REINPLACE_CMD} -e '/COMPILE_WITH_PLIB/ d' ${WRKSRC}/CMakeLists.txt
.endif

.if ! ${PORT_OPTIONS:MGUI}
	@${REINPLACE_CMD} -e '/COMPILE_WITH_FLTK/ d' ${WRKSRC}/CMakeLists.txt
.endif

	@${REINPLACE_CMD} -e 's|string sDataDir|&="${DATADIR}/data/"|'\
		${WRKSRC}/src/base/conf.cc
	@${REINPLACE_CMD} -e '/LUABIND_SCRIPTS_DIR/ s|"scripts"|"${DATADIR}/scripts"|' \
		${WRKSRC}/src/lua_bind/defs.hh
	@${REINPLACE_CMD} -e 's|doc/html/|${DOCSDIR}/|' ${WRKSRC}/src/gui/gui.cc

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data scripts" ${STAGEDIR}${DATADIR})
# DOCS are used from within the game, so this is unconditional
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

	${LN} -sf ${DOCSDIR}/images/palominoLogo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
