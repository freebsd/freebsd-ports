# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ogre3d
PORTVERSION=	1.9.0
PORTREVISION=	17
CATEGORIES=	graphics devel
MASTER_SITES=   https://bitbucket.org/sinbad/ogre/get/
DISTNAME=	v1-9-0

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Scene-oriented, flexible 3D engine written in C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libzzip.so:devel/zziplib \
		libfreetype.so:print/freetype2 \
		libfreeimage.so:graphics/freeimage

USE_LDCONFIG=	yes
USES=		tar:bzip2 cmake pkgconfig compiler:c++11-lib
USE_SDL=	sdl
USE_XORG=	xaw xrandr
WRKSRC=		${WRKDIR}/sinbad-ogre-dd30349ea667

OPTIONS_DEFINE=	BOOST DOCS
OPTIONS_SUB=	yes

BOOST_BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
BOOST_RUN_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

BROKEN_aarch64=		does not compile: error: class member cannot be redeclared
BROKEN_powerpc=		does not install

post-patch:
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

post-patch-BOOST-off:
	@${REINPLACE_CMD} -e 's|Boost|No_Boost|g' \
		${WRKSRC}/CMake/Dependencies.cmake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README COPYING AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
