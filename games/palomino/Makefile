# New ports collection makefile for:	palomodulesmemino
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palomino
PORTVERSION=	20120105
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.palomino3d.org/sim/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.txz \
		${PORTNAME}_data_misc_${MISC_VER}.tar.bz2 \
		${PORTNAME}_data_models_${MODELS_VER}.tar.bz2 \
		${PORTNAME}_data_sounds_${SOUNDS_VER}.tar.bz2 \
		${PORTNAME}_data_terrain_${TERRAIN_VER}.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Action flight simulator with its own 3D engine

LIB_DEPENDS=	osg.55:${PORTSDIR}/graphics/osg

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

OPTIONS=	JOYSTICK "Enable joystick support through linux-js" off \
		SDL	"SDL support for input and sound" on \
		PLIB	"Enable sound support through plib" off \
		GUI	"Enable FLTK GUI" on

.include <bsd.port.pre.mk>

.if defined(WITH_JOYSTICK)
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
RUN_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
.endif

.if !defined(WITHOUT_SDL)
USE_SDL+=	sdl mixer
.endif

.if defined(WITHOUT_PLIB)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
.endif

.if !defined(WITHOUT_GUI)
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR}; \
	for file in ${DISTFILES}; do \
		if ${ECHO_CMD} $$file | ${GREP} -q txz$$; then \
			${XZ_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS}; \
		else \
			${BZIP2_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS}; \
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
.if !defined(WITH_JOYSTICK)
	@${REINPLACE_CMD} -e '/COMPILE_WITH_LINUX_JOYSTICK/ d' ${WRKSRC}/CMakeLists.txt
.endif
.if defined(WITHOUT_SDL)
	@${REINPLACE_CMD} -e '/COMPILE_WITH_SDL/ d' ${WRKSRC}/CMakeLists.txt
.endif
.if !defined(WITH_PLIB)
	@${REINPLACE_CMD} -e '/COMPILE_WITH_PLIB/ d' ${WRKSRC}/CMakeLists.txt
.endif
.if defined(WITHOUT_GUI)
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
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} "*" ${DOCSDIR}/

.include <bsd.port.post.mk>
