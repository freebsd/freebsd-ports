# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	3.6.2
DISTVERSIONPREFIX=	${GH_PROJECT}_
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	GH

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters

LICENSE=	NOSA13
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpthread-stubs.so:devel/libpthread-stubs \
		libjpeg.so:graphics/jpeg-turbo \
		libdrm.so:graphics/libdrm \
		libpng16.so:graphics/png \
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

USE_GL		+= gl

BROKEN_FreeBSD_9=	dependency graphics/code-eli needs additional math functions

USE_GITHUB=	yes
GH_PROJECT=	OpenVSP
GH_ACCOUNT=	${GH_PROJECT}

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_PROJECT}_${PORTVERSION}

CMAKE_SOURCE_PATH=	${WRKSRC}/SuperProject
USES=		cmake:outsource compiler:gcc-c++11-lib
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
USE_GL=		glu
USE_GNOME=	libxml2
CFLAGS+=	-I${LOCALBASE}/include/openNURBS

BUILD_PREFIX=	OpenVSP-prefix/src/OpenVSP-build/_CPack_Packages/FreeBSD/ZIP/OpenVSP-${PORTVERSION}-FreeBSD

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${BUILD_PREFIX}/vsp* ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
.for d in CustomScripts airfoil matlab scripts textures
	(cd ${BUILD_WRKSRC}/${BUILD_PREFIX}/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
.endfor
	${CP} ${BUILD_WRKSRC}/${BUILD_PREFIX}/LICENSE ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
