# New ports collection makefile for:	freeorion
# Date created:				2007-04-29
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	freeorion
PORTVERSION=	0.3.13.3318
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	oliver

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Open-source, platform independent galactic conquest game

LIB_DEPENDS=	GiGi.0:${PORTSDIR}/x11-toolkits/gigi \
		alut.1:${PORTSDIR}/audio/freealut \
		graph:${PORTSDIR}/graphics/graphviz \
		log4cpp.4:${PORTSDIR}/devel/log4cpp \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	${LOCALBASE}/lib/libbulletmath.a:${PORTSDIR}/devel/bullet
BUILD_DEPENDS=	${LOCALBASE}/lib/libbulletmath.a:${PORTSDIR}/devel/bullet

USE_GCC=	4.4+
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_SCONS=	yes
SCONS_ARGS=	with_builtin_sdlnet=0
SCONS_BUILDENV=	PYTHON_LIB=${PYTHON_VERSION} LINKFLAGS=${LDFLAGS}
USE_SDL=	sdl net
WRKSRC=		${WRKDIR}/${PORTNAME}/FreeOrion

.if defined(WITH_DEBUG)
SCONS_ARGS+=	debug=1
.else
SCONS_ARGS+=	release=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Plugin=Plugin_CgProgramManager|#&|g; \
		s|\(PluginFolder=\)\.|\1${LOCALBASE}/lib/OGRE|g' \
		${WRKSRC}/ogre_plugins.cfg
	@${REINPLACE_CMD} -e 's|\(prefix.*\)/usr/local|\1${PREFIX}|g; \
		s|/usr/local/lib/OGRE|${LOCALBASE}/lib/OGRE|g' \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/util/Directories.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ogre_plugins.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/OISInput.cfg ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/resources.cfg ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/GLX_icon.png ${DATADIR}/default/data/art

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export https://${PORTNAME}.svn.sourceforge.net/svnroot/${PORTNAME}/trunk ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.mk>
