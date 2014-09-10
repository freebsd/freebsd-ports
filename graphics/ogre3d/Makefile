# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ogre3d
PORTVERSION=	1.9.0
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=   https://bitbucket.org/sinbad/ogre/get/
DISTNAME=	v1-9-0
WRKSRC=		${WRKDIR}/sinbad-ogre-dd30349ea667

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Scene-oriented, flexible 3D engine written in C++

LIB_DEPENDS=	libzzip.so:${PORTSDIR}/devel/zziplib \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfreeimage.so:${PORTSDIR}/graphics/freeimage

OPTIONS_DEFINE=	BOOST DOCS

USE_LDCONFIG=	yes
USES=		tar:bzip2 cmake pkgconfig compiler:c++11-lib
USE_SDL=	sdl
USE_XORG=	xaw xrandr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOOST}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
PLIST_SUB+=	BOOSTTRUE=""
PLIST_SUB+=	BOOSTFALSE="@comment "
.else
PLIST_SUB+=	BOOSTTRUE="@comment "
PLIST_SUB+=	BOOSTFALSE=""
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc
.endif

post-patch:
.if ! ${PORT_OPTIONS:MBOOST}
	@${REINPLACE_CMD} -e 's|Boost|No_Boost|g' \
		${WRKSRC}/CMake/Dependencies.cmake
.endif
	# disable OIS, POCO, TBB detection
	@${REINPLACE_CMD} -e 's|include(FindPkgMacros)|return()|g' \
		${WRKSRC}/CMake/Packages/FindOIS.cmake \
		${WRKSRC}/CMake/Packages/FindPOCO.cmake \
		${WRKSRC}/CMake/Packages/FindTBB.cmake
	@${REINPLACE_CMD} -e 's|\(OGRE_RW_MUTEX[^;]*\)$$|\1;|g' \
		${WRKSRC}/OgreMain/include/OgreWorkQueue.h
	@${REINPLACE_CMD} -e 's|\(OGRE_RW_MUTEX.*\);$$|\1|g' \
		${WRKSRC}/OgreMain/include/Threading/OgreThreadDefinesBoost.h
	@${REINPLACE_CMD} -e '\
		s,defined(__x86_64__),& || defined(__powerpc__) || defined(__sparc64__) || defined(__amd64__),' \
		${WRKSRC}/OgreMain/include/OgrePlatform.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README COPYING AUTHORS
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
