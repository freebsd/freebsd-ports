# New ports collection makefile for:	ogre3d
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogre3d
PORTVERSION=	1.0.5
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=ogre
DISTNAME=	ogre-linux_osx-v1-0-5

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A scene-oriented, flexible 3D engine written in C++

LIB_DEPENDS=	zzip.10:${PORTSDIR}/devel/zziplib \
		CEGUIBase.0:${PORTSDIR}/graphics/cegui

WRKSRC=		${WRKDIR}/ogrenew
CONFIGURE_ARGS=	--disable-cg --program-transform-name=
USE_REINPLACE=	YES
USE_LIBTOOL_VER=13
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
	@${REINPLACE_CMD} -e '\
		s|\(-L$$(top_builddir)/OgreMain/src\)\([$$ ]*\)|\1/.libs\2|; \
		s|\$$(INSTALL_PROGRAM) .libs/|\$$(INSTALL_PROGRAM) |' \
		${WRKSRC}/Samples/*/src/Makefile.in \
		${WRKSRC}/Tools/*/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-L$$(top_builddir)/Samples/Common/CEGUIRenderer/src|&/.libs|' \
		${WRKSRC}/Samples/Gui/src/Makefile.in
	@${REINPLACE_CMD} -e 's|<CEGUI/|<|g' \
		${WRKSRC}/Samples/Gui/src/Gui.cpp \
		${WRKSRC}/Samples/Common/CEGUIRenderer/include/OgreCEGUIResourceProvider.h \
		${WRKSRC}/Samples/Common/CEGUIRenderer/include/OgreCEGUITexture.h \
		${WRKSRC}/Samples/Common/CEGUIRenderer/include/OgreCEGUIRenderer.h \
		${WRKSRC}/Samples/Common/CEGUIRenderer/src/OgreCEGUIRenderer.cpp \
		${WRKSRC}/Samples/Common/CEGUIRenderer/src/OgreCEGUIResourceProvider.cpp \
		${WRKSRC}/Samples/Common/CEGUIRenderer/src/OgreCEGUITexture.cpp
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Samples/Terrain/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS ChangeLog
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
