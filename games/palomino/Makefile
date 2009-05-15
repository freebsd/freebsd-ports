# New ports collection makefile for:	palomodulesmemino
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palomino
PORTVERSION=	20090511
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-sim \
		ftp://ftp.palomino3d.org/sim/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_data_misc_${MISC_VER}${EXTRACT_SUFX} \
		${PORTNAME}_data_models_${MODELS_VER}${EXTRACT_SUFX} \
		${PORTNAME}_data_sounds_${SOUNDS_VER}${EXTRACT_SUFX} \
		${PORTNAME}_data_terrain_${TERRAIN_VER}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Action flight simulator with its own 3D engine

LIB_DEPENDS=	osg.55:${PORTSDIR}/graphics/osg

USE_BZIP2=	yes
USE_GL=		gl
USE_CMAKE=	yes
USE_LUA=	5.1
LUA_COMPS=	lua:build
MAKE_JOBS_SAFE=	yes

MISC_VER=	20081206
MODELS_VER=	20090511
SOUNDS_VER=	20080704
TERRAIN_VER=	20080206

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	JOYSTICK "Enable joystick support through linux-js" on \
		SOUND	"Enable sound support through plib" on \
		GUI	"Enable FLTK GUI" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_JOYSTICK)
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
RUN_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
.endif

.if !defined(WITHOUT_SOUND)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
.endif

.if !defined(WITHOUT_GUI)
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.endif

post-patch:
	@${REINPLACE_CMD} -e '/COMMAND/ s|lua|${LUA_CMD}|' \
		${WRKSRC}/build/lua_bind/CMakeLists.txt
.if defined(WITHOUT_JOYSTICK)
	@${REINPLACE_CMD} -e 's|OS_FREEBSD|0|' ${WRKSRC}/src/input/joystick.* \
		${WRKSRC}/src/input/joystick_linux.* ${WRKSRC}/src/control/conf.cc
.endif
	@${REINPLACE_CMD} -e '/FIND_PACKAGE(/ s|)| REQUIRED)|' \
		${WRKSRC}/CMakeLists.txt
.if defined(WITHOUT_SOUND)
	@${REINPLACE_CMD} -e '/FIND_PACKAGE(PLIB/ d' ${WRKSRC}/CMakeLists.txt
.endif
.if defined(WITHOUT_GUI)
	@${REINPLACE_CMD} -e '/FIND_PACKAGE(FLTK/ d' ${WRKSRC}/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e '/FIND_PACKAGE(OSSIM/ d' ${WRKSRC}/CMakeLists.txt
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
