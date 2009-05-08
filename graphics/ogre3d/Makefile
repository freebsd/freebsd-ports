# New ports collection makefile for:	ogre3d
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogre3d
PORTVERSION=	1.6.2
CATEGORIES=	graphics devel
MASTER_SITES=	SF/ogre
DISTNAME=	ogre-v${PORTVERSION:S/./-/g:S/-r1/RC1/g}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A scene-oriented, flexible 3D engine written in C++

LIB_DEPENDS=	zzip.13:${PORTSDIR}/devel/zziplib \
		CEGUIBase.3:${PORTSDIR}/graphics/cegui \
		IL.2:${PORTSDIR}/graphics/devil

WRKSRC=		${WRKDIR}/ogre
CONFIGURE_ARGS=	--disable-cg --program-transform-name= --enable-static \
		--with-cppunit-prefix=/nonexistent --disable-freeimage
CONFIGURE_ENV+=	ZZIPLIB_CFLAGS="-I${LOCALBASE}/include" \
		ZZIPLIB_LIBS="-L${LOCALBASE}/lib -lzzip"

OPTIONS=	GTK	"Use GTK instead of Xt gui"	off \
		DEBUG	"Enable debug mode"		off \
		DEMOS	"Build OGRE demos"		off

GNU_CONFIGURE=	YES
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	YES
USE_BZIP2=	YES
USE_GNOME=	gnomehack
USE_GMAKE=	YES
USE_SDL=	sdl
USE_XORG=	xaw
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CONFIGURE_ENV+= CPPFLAGS="-I${X11BASE}/include -DNDEBUG"
.else
CONFIGURE_ENV+= CPPFLAGS="-I${X11BASE}/include"
.endif

.if defined(WITH_DEMOS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
RUN_DEPENDS+=	${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
.else
CONGIGURE_ARGS+=--disable-ogre-demos
.endif

.if defined(WITH_GTK)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--with-gui=gtk
PLIST_SUB+=	WITH_GTK=""
.else
CONFIGURE_ARGS+=--with-gui=Xt
PLIST_SUB+=	WITH_GTK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '\
		s|-pthread|${PTHREAD_LIBS}|g; \
		s|"-lIL|"-L${LOCALBASE}/lib -lIL|g; \
		s|-lGL -lGLU|-L${X11BASE}/lib &|g; \
		s|" == "x|" = "x|g; \
		s|-lfreeimage|-L${LOCALBASE}/lib &|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| -Wl,-z,defs||' \
		${WRKSRC}/PlugIns/BSPSceneManager/src/Makefile.in \
		${WRKSRC}/PlugIns/CgProgramManager/src/Makefile.in \
		${WRKSRC}/PlugIns/EXRCodec/src/Makefile.in \
		${WRKSRC}/PlugIns/OctreeSceneManager/src/Makefile.in \
		${WRKSRC}/PlugIns/ParticleFX/src/Makefile.in \
		${WRKSRC}/RenderSystems/GL/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
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

.include <bsd.port.post.mk>
