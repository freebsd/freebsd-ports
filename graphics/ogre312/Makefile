# New ports collection makefile for:	ogre3d
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogre3d
PORTVERSION=	1.0.6
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=ogre
DISTNAME=	ogre-linux_osx-v${PORTVERSION:S/./-/g}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A scene-oriented, flexible 3D engine written in C++

LIB_DEPENDS=	zzip.10:${PORTSDIR}/devel/zziplib \
		CEGUIBase.0:${PORTSDIR}/graphics/cegui

WRKSRC=		${WRKDIR}/ogrenew
CONFIGURE_ARGS=	--disable-cg --program-transform-name= --enable-static
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_GCC=	3.4
USE_BZIP2=	YES
USE_X_PREFIX=	YES
USE_GNOME=	gnomehack
USE_SDL=	sdl
USE_GMAKE=	YES

post-patch:
	@${REINPLACE_CMD} -e '\
		s|sdl-config|${SDL_CONFIG}|g ;\
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|"-lIL|"-L${LOCALBASE}/lib -lIL|g; \
		s|-lGL -lGLU|-L${X11BASE}/lib &|g; \
		s|GLSUPPORT_CFLAGS=\$$SDL_CFLAGS|GLSUPPORT_CFLAGS="-I${X11BASE}/include \$$SDL_CFLAGS"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<CEGUI/|<|g' \
		${WRKSRC}/Samples/Gui/src/Gui.cpp \
		${WRKSRC}/Samples/Common/CEGUIRenderer/include/OgreCEGUIResourceProvider.h \
		${WRKSRC}/Samples/Common/CEGUIRenderer/include/OgreCEGUITexture.h \
		${WRKSRC}/Samples/Common/CEGUIRenderer/include/OgreCEGUIRenderer.h \
		${WRKSRC}/Samples/Common/CEGUIRenderer/src/OgreCEGUIRenderer.cpp \
		${WRKSRC}/Samples/Common/CEGUIRenderer/src/OgreCEGUIResourceProvider.cpp \
		${WRKSRC}/Samples/Common/CEGUIRenderer/src/OgreCEGUITexture.cpp
	@${REINPLACE_CMD} -e 's| -Wl,-z,defs||' \
		${WRKSRC}/PlatformManagers/SDL/src/Makefile.in \
		${WRKSRC}/PlugIns/BSPSceneManager/src/Makefile.in \
		${WRKSRC}/PlugIns/ParticleFX/src/Makefile.in \
		${WRKSRC}/PlugIns/OctreeSceneManager/src/Makefile.in \
		${WRKSRC}/RenderSystems/GL/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Samples/Terrain/src/Makefile.in
	@${REINPLACE_CMD} -e '\
		s,defined(__x86_64__),& || defined(__powerpc__) || defined(__ia64__) || defined(__sparc64__) || defined(__alpha__) || defined(__amd64__),' \
		${WRKSRC}/OgreMain/include/OgrePlatform.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
