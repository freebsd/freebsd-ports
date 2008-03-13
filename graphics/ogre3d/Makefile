# New ports collection makefile for:	ogre3d
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogre3d
PORTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=ogre
DISTNAME=	ogre-linux_osx-v${PORTVERSION:S/./-/g}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A scene-oriented, flexible 3D engine written in C++

LIB_DEPENDS=	zzip.13:${PORTSDIR}/devel/zziplib \
		CEGUIBase.1:${PORTSDIR}/graphics/cegui \
		IL.1:${PORTSDIR}/graphics/devil

WRKSRC=		${WRKDIR}/ogrenew
CONFIGURE_ARGS=	--disable-cg --program-transform-name= --enable-static \
		--with-cppunit-prefix=/nonexistent --disable-freeimage
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include -DNDEBUG" \
		ZZIPLIB_CFLAGS="-I${LOCALBASE}/include" \
		ZZIPLIB_LIBS="-L${LOCALBASE}/lib -lzzip"
GNU_CONFIGURE=	YES
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	YES
USE_BZIP2=	YES
USE_XLIB=	YES
#USE_GCC=	3.4
USE_GNOME=	gnomehack
USE_GMAKE=	YES
USE_SDL=	sdl

post-patch:
	@${REINPLACE_CMD} -e '\
		s|sdl-config|${SDL_CONFIG}|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|"-lIL|"-L${LOCALBASE}/lib -lIL|g; \
		s|-lGL -lGLU|-L${X11BASE}/lib &|g; \
		s|" == "x|" = "x|g; \
		s|-lfreeimage|-L${LOCALBASE}/lib &|g' \
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
		${WRKSRC}/PlugIns/BSPSceneManager/src/Makefile.in \
		${WRKSRC}/PlugIns/CgProgramManager/src/Makefile.in \
		${WRKSRC}/PlugIns/EXRCodec/src/Makefile.in \
		${WRKSRC}/PlugIns/OctreeSceneManager/src/Makefile.in \
		${WRKSRC}/PlugIns/ParticleFX/src/Makefile.in \
		${WRKSRC}/RenderSystems/GL/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Samples/Terrain/src/Makefile.in
	@${REINPLACE_CMD} -e 's|(CEGUI::uint)|(size_t)|' \
		${WRKSRC}/Samples/OceanDemo/src/OceanDemo.cpp
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
