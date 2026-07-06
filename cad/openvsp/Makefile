PORTNAME=	openvsp
DISTVERSIONPREFIX=	${GH_PROJECT}_
DISTVERSION=	3.51.0
CATEGORIES=	cad

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters
WWW=		http://www.openvsp.org/

LICENSE=	NOSA13
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=		fails to compile: invokes x86 asm

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm \
		pandoc:textproc/hs-pandoc
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libcpptest.so:devel/cpptest \
		libdbus-1.so:devel/dbus \
		libClipper2.so:cad/Clipper2 \
		libeigen_blas.so:math/eigen5 \
		libcminpack.so:math/cminpack \
		libharfbuzz.so:print/harfbuzz \
		libxkbcommon.so:x11/libxkbcommon \
		libdecor-0.so:x11-toolkits/libdecor

USES=		cmake:noninja localbase gettext-runtime gl gnome \
		jpeg localbase xorg

.if !exists(/usr/include/omp.h)
CXXFLAGS+=	-fpermissive
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif
USE_GITHUB=	yes
GH_ACCOUNT=	${GH_PROJECT}
GH_PROJECT=	OpenVSP

USE_GL=		gl glew glu
USE_GNOME=	cairo glib20 libxml2 pango
USE_XORG=	ice sm x11 xau xcb xcursor xdamage xdmcp xext xfixes xft \
		xinerama xrender xxf86vm

CMAKE_ARGS=	-DVSP_USE_SYSTEM_CMINPACK:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_CPPTEST:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_CODEELI:BOOLEAN=no \
		-DVSP_USE_SYSTEM_EIGEN:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_LIBXML2:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_FLTK:boolean=no \
		-DCMAKE_PREFIX_PATH=${PREFIX} \
		-DVSP_USE_SYSTEM_GLM:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_CLIPPER2:BOOLEAN=yes \
		-DVSP_USE_SYSTEM_GLEW:BOOLEAN=yes
CMAKE_INSTALL_PREFIX=	${STAGEDIR}${PREFIX}
CMAKE_SOURCE_PATH=	${WRKSRC}/SuperProject

BUILD_PREFIX=	OpenVSP-prefix/src/OpenVSP-build/_CPack_Packages/FreeBSD/ZIP/OpenVSP-${DISTVERSION}-FreeBSD

MAKE_JOBS_UNSAFE=yes

CXXFLAGS_powerpc64=	-mvsx

post-patch:
	@${REINPLACE_CMD} 's/fltk::gl/fltk_gl/' ${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/src/vsp_aero/Viewer/CMakeLists.txt

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${BUILD_PREFIX}/vspIcon.png ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${PREFIX}/vspIcon.png ${BUILD_WRKSRC}/${BUILD_PREFIX}/vspIcon.png
.for f in vsp vspaero vspaero_opt vsploads vspscript vspviewer
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${BUILD_PREFIX}/${f} ${STAGEDIR}${PREFIX}/bin
	${RM} ${STAGEDIR}${PREFIX}/${f}
.endfor
.for d in CustomScripts airfoil matlab scripts textures
	(cd ${BUILD_WRKSRC}/${BUILD_PREFIX}/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${RM} -rf ${STAGEDIR}${PREFIX}/${d}
.endfor
	${CP} ${BUILD_WRKSRC}/${BUILD_PREFIX}/LICENSE ${STAGEDIR}${DATADIR}
	${CP} ${BUILD_WRKSRC}/${BUILD_PREFIX}/README.md ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${PREFIX}/LICENSE
	${RM} ${STAGEDIR}${PREFIX}/README.md

.include <bsd.port.mk>
