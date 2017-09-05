# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	3.13.1
DISTVERSIONPREFIX=	${GH_PROJECT}_
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters

LICENSE=	NOSA13
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfltk.so:x11-toolkits/fltk \
		libGLEW.so:graphics/glew \
		libcpptest.so:devel/cpptest
BUILD_DEPENDS=	${LOCALBASE}/lib/libopenNURBS.a:graphics/opennurbs \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs

CMAKE_SOURCE_PATH=	${WRKSRC}/SuperProject
CMAKE_INSTALL_PREFIX=	${STAGEDIR}${PREFIX}

USES=		cmake:outsource,noninja jpeg

USE_GITHUB=	yes
GH_PROJECT=	OpenVSP
GH_ACCOUNT=	${GH_PROJECT}

# On FreeBSD < 11 libc++ lacks support for sized delete operators.
# GCC dropped the builtin version of these operators in 6+ by
# defaulting to gnu++14. Force c++11 instead.
# For a more detailed discussion see:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=219484
USE_CXXSTD=	gnu++11

CMAKE_ARGS=	-DVSP_USE_SYSTEM_CMINPACK:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_CPPTEST:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_CODEELI:BOOLEAN=no \
		-DVSP_USE_SYSTEM_EIGEN:BOOLEAN=no \
		-DVSP_USE_SYSTEM_LIBXML2:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_FLTK:boolean=yes \
		-DVSP_USE_SYSTEM_CMINPACK:boolean=no \
		-DVSP_USE_SYSTEM_GLM:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_GLEW:BOOLEAN=yes
USE_XORG=	ice sm x11 xau xcb xdamage xdmcp xext xfixes xft \
		xinerama xrender xxf86vm
USE_GL=		gl glu

USE_GNOME=	libxml2
CFLAGS+=	-I${LOCALBASE}/include/openNURBS

.include <bsd.port.options.mk>

# In 12 gcc can not compile the port so switch to clang 5.0.0 in base.
# But wait! It crashes while compiling so apply a patch to avoid weird asm code
# that makes clang die
# For details see:
# https://lists.freebsd.org/pipermail/freebsd-hackers/2017-August/051352.html

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200000
USES+=	compiler:c++11-lib
EXTRA_PATCHES=	${FILESDIR}/extra-src_external_angelscript_sdk_angelscript_source_as__callfunc__x86.cpp
CFLAGS+=	-I${LOCALBASE}/include
.else
USES+=	compiler:gcc-c++11-lib
.endif

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
