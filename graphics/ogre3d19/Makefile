PORTNAME=	ogre3d
PORTVERSION=	1.9.0
PORTREVISION=	21
CATEGORIES=	graphics devel
MASTER_SITES=	https://bitbucket.org/sinbad/ogre/get/
PKGNAMESUFFIX=	19
DISTNAME=	v1-9-0

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Scene-oriented, flexible 3D engine written in C++ (legacy version 1.9)
WWW=		https://www.ogre3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	does not compile: OgreMain/include/OgreStringConverter.h:126:23: class member cannot be redeclared
BROKEN_powerpc=	does not install
BROKEN_riscv64=	does not compile: OgreMain/include/OgreStringConverter.h:126:23: class member cannot be redeclared

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libzzip.so:devel/zziplib

USES=		cmake compiler:c++11-lib gl pkgconfig sdl tar:bzip2 xorg
USE_CXXSTD=	c++14
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_SDL=	sdl
USE_XORG=	ice sm x11 xaw xext xrandr xt

CONFLICTS=	ogre3d

WRKSRC=		${WRKDIR}/sinbad-ogre-dd30349ea667

OPTIONS_DEFINE=	BOOST DOCS
OPTIONS_SUB=	yes

BOOST_BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
BOOST_RUN_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

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
		s,defined(__x86_64__),& || defined(__powerpc__) || defined(__amd64__),' \
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
