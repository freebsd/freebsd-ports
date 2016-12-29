# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	3.9.1
DISTVERSIONPREFIX=	${GH_PROJECT}_
PORTREVISION=	2
CATEGORIES=	cad

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters

LICENSE=	NOSA13
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpthread-stubs.so:devel/libpthread-stubs \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfltk.so:x11-toolkits/fltk \
		libGLEW.so:graphics/glew \
		libcpptest.so:devel/cpptest
BUILD_DEPENDS=	${LOCALBASE}/lib/libopenNURBS.a:graphics/opennurbs \
		${LOCALBASE}/include/eli/code_eli.hpp:graphics/code-eli \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/include/eigen3/Eigen/Array:math/eigen3

BROKEN_FreeBSD_9=	dependency graphics/code-eli needs additional math functions

USE_GITHUB=	yes
GH_PROJECT=	OpenVSP
GH_ACCOUNT=	${GH_PROJECT}

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_PROJECT}_${PORTVERSION}

CMAKE_SOURCE_PATH=	${WRKSRC}/SuperProject
CMAKE_INSTALL_PREFIX=	${STAGEDIR}${PREFIX}
USES=		cmake:outsource jpeg

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000 && ${OSVERSION} < 1002000
# Fails to build with GCC 4.9 in 10.1
USE_GCC=	4.8
LDFLAGS+=	-L${LOCALBASE}/lib/c++
CXXFLAGS+=	-nostdinc++ -isystem ${LOCALBASE}/include/c++/v1
BUILD_DEPENDS+=	${LOCALBASE}/lib/c++/libstdc++.so:devel/libc++
.else
USES +=		compiler:gcc-c++11-lib
.endif

CMAKE_ARGS=	-DVSP_USE_SYSTEM_CMINPACK:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_CPPTEST:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_LIBXML2:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_EIGEN:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_FLTK:boolean=yes \
		-DVSP_USE_SYSTEM_CMINPACK:boolean=no \
		-DVSP_USE_SYSTEM_GLM:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_GLEW:BOOLEAN=yes
USE_XORG=	ice sm x11 xau xcb xdamage xdmcp xext xfixes xft \
		xinerama xrender xxf86vm
USE_GL=		gl glu

USE_GNOME=	libxml2
CFLAGS+=	-I${LOCALBASE}/include/openNURBS

BUILD_PREFIX=	OpenVSP-prefix/src/OpenVSP-build/_CPack_Packages/FreeBSD/ZIP/OpenVSP-${PORTVERSION}-FreeBSD

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${BUILD_PREFIX}/vsp* ${STAGEDIR}${PREFIX}/bin
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/vsp*
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in CustomScripts airfoil matlab scripts textures
	(cd ${BUILD_WRKSRC}/${BUILD_PREFIX}/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
.endfor
	${CP} ${BUILD_WRKSRC}/${BUILD_PREFIX}/LICENSE ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
