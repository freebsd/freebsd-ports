# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	palomino
PORTVERSION=	20121026
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.palomino3d.org/sim/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.txz \
		${PORTNAME}_data_misc_${MISC_VER}.tar.bz2 \
		${PORTNAME}_data_models_${MODELS_VER}.tar.bz2 \
		${PORTNAME}_data_sounds_${SOUNDS_VER}.tar.bz2 \
		${PORTNAME}_data_terrain_${TERRAIN_VER}.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Action flight simulation computer program using OSG

LIB_DEPENDS=	osg:${PORTSDIR}/graphics/osg

USE_BZIP2=	yes
USE_XZ=		yes
USE_GL=		gl
USE_CMAKE=	yes
USE_LUA=	5.1
LUA_COMPS=	lua:build
MAKE_JOBS_SAFE=	yes

MISC_VER=	20091027
MODELS_VER=	20090615
SOUNDS_VER=	20080704
TERRAIN_VER=	20080206

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	JOYSTICK SDL PLIB GUI
OPTIONS_DEFAULT=	SDL GUI

JOYSTICK_DESC=	Enable joystick support through linux-js
SDL_DESC=	SDL support for input and sound
PLIB_DESC=	Enable sound support through plib
GUI_DESC=	Enable FLTK GUI

DESKTOP_ENTRIES=	"Palomino" "${COMMENT}" "${PORTNAME}" \
			"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJOYSTICK}
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
RUN_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl mixer
.endif

.if ${PORT_OPTIONS:MPLIB}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
.endif

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	fltk:${PORTSDIR}/x11-toolkits/fltk
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR}; \
	for distfile in ${DISTFILES}; do \
		if ${ECHO_CMD} $$distfile | ${GREP} -q txz$$; then \
			${XZ_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$distfile ${EXTRACT_AFTER_ARGS}; \
		else \
			${BZIP2_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$distfile ${EXTRACT_AFTER_ARGS}; \
		fi; \
	done

post-patch:
	@${FIND} ${WRKSRC}/CMakeModules -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g'
	@${REINPLACE_CMD} -e '/ rt / d' ${WRKSRC}/CMakeModules/libraries.cmake
	@${REINPLACE_CMD} -e '/COMMAND/ s|lua|${LUA_CMD}|' \
		${WRKSRC}/build/lua_bind/CMakeLists.txt
	@${REINPLACE_CMD} -e '/FIND_PACKAGE(/ s|)| REQUIRED)|' \
		${WRKSRC}/CMakeModules/libraries.cmake
	@${REINPLACE_CMD} -e '/COMPILE_WITH_OSSIM/ d' ${WRKSRC}/CMakeLists.txt
.if empty(PORT_OPTIONS:MJOYSTICK)
	@${REINPLACE_CMD} -e '/COMPILE_WITH_LINUX_JOYSTICK/ d' ${WRKSRC}/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MSDL)
	@${REINPLACE_CMD} -e '/COMPILE_WITH_SDL/ d' ${WRKSRC}/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MPLIB)
	@${REINPLACE_CMD} -e '/COMPILE_WITH_PLIB/ d' ${WRKSRC}/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MGUI)
	@${REINPLACE_CMD} -e '/COMPILE_WITH_FLTK/ d' ${WRKSRC}/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's|string sDataDir|&="${DATADIR}/data/"|'\
	       	${WRKSRC}/src/base/conf.cc
	@${REINPLACE_CMD} -e '/LUABIND_SCRIPTS_DIR/ s|"scripts"|"${DATADIR}/scripts"|' \
	       	${WRKSRC}/src/lua_bind/defs.hh
	@${REINPLACE_CMD} -e 's|doc/html/|${DOCSDIR}/|' ${WRKSRC}/src/gui/gui.cc

post-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} "data scripts" ${DATADIR}/
# docs are used from within the game, so this is unconditional
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/

	${LN} -sf ${DOCSDIR}/images/palominoLogo.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
