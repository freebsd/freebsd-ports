PORTNAME=	appleseed
DISTVERSION=	2.1.0-beta
PORTREVISION=	21
CATEGORIES=	graphics

PATCH_SITES=	http://vault.101011010.xyz/distfiles/ LOCAL/danfe
PATCHFILES=	OSL-01.13.7.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern, physically-based production renderer
WWW=		https://appleseedhq.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		fails to build with Boost>=1.87

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		liblz4.so:archivers/liblz4 \
		libpng.so:graphics/png \
		libIlmThread.so:graphics/openexr \
		libImath.so:math/Imath \
		libOpenColorIOv1.so:graphics/opencoloriov1 \
		libOpenImageIO.so:graphics/openimageio \
		libxerces-c.so:textproc/xerces-c3 \
		liboslexec.so:graphics/openshadinglanguage

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}hq

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	not ported to it yet

USES=		cmake compiler:c++11-lang shebangfix
SHEBANG_FILES=	scripts/*.py

CMAKE_ARGS=	-DWITH_PYTHON2_BINDINGS:BOOL=OFF \
		-DWITH_DOXYGEN:BOOL=OFF \
		-DINSTALL_HEADERS:BOOL=OFF \
		-DINSTALL_TESTS:BOOL=OFF \
		-DINSTALL_API_EXAMPLES:BOOL=OFF \
		-DWARNINGS_AS_ERRORS:BOOL=OFF

.for lib in BOOST EMBREE EXR OCIO OIIO OSL
CMAKE_ARGS+=	-DUSE_STATIC_${lib}:BOOL=OFF
.endfor

# Not ready for hier(7)-conforming installation yet
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PKGBASE}
PLIST_SUB=	APPHOME=${CMAKE_INSTALL_PREFIX}

SUB_FILES=	pkg-message
SUB_LIST:=	${PLIST_SUB}

OPTIONS_DEFINE=	EMBREE PYTHON STUDIO
OPTIONS_DEFAULT=	PYTHON STUDIO
OPTIONS_SUB=	yes

EMBREE_DESC=	Embree intersection backend support
EMBREE_LIB_DEPENDS=	libembree3.so:graphics/embree3
EMBREE_CMAKE_ON=	-DWITH_EMBREE:BOOL=ON

PYTHON_USES=	gl python:build,run
PYTHON_USE=	GL=gl
PYTHON_CMAKE_ON=	-DWITH_PYTHON3_BINDINGS:BOOL=ON

STUDIO_DESC=	Build appleseed.studio (Qt-based)
STUDIO_LIB_DEPENDS=	${PY_BOOST}
STUDIO_USES=	qt:5
STUDIO_USE=	QT=buildtools:build,qmake:build,concurrent,core,gui,opengl,widgets
STUDIO_CMAKE_OFF=	-DWITH_STUDIO:BOOL=OFF
STUDIO_IMPLIES=	PYTHON

post-patch:
	@${RMDIR} ${WRKSRC}/sandbox/docs/api
	@${RM} ${WRKSRC}/sandbox/share/cmake/Modules/FindOpenImageIO.cmake
	@${REINPLACE_CMD} -e 's,OpenEXR,Imath, ; /[ {]IMATH_HALF_LIBRARY/d' \
		${WRKSRC}/cmake/modules/FindImath.cmake
	@${REINPLACE_CMD} -e 's,OpenEXR/Imath,Imath/Imath,' \
                ${WRKSRC}/src/appleseed/foundation/meta/tests/test_matrix.cpp \
                ${WRKSRC}/src/appleseed/foundation/meta/tests/test_quaternion.cpp \
                ${WRKSRC}/src/appleseed/foundation/meta/tests/test_vector.cpp \
                ${WRKSRC}/src/appleseed/foundation/meta/tests/test_aabb.cpp \
                ${WRKSRC}/src/appleseed/foundation/meta/tests/test_color.cpp \
                ${WRKSRC}/src/appleseed/foundation/math/vector.h \
                ${WRKSRC}/src/appleseed/foundation/math/aabb.h \
                ${WRKSRC}/src/appleseed/foundation/math/matrix.h \
                ${WRKSRC}/src/appleseed/foundation/math/quaternion.h \
                ${WRKSRC}/src/appleseed/foundation/image/color.h
	@${REINPLACE_CMD} -e '/return Product/s,trt\.derived(),trt,' \
		${WRKSRC}/src/thirdparty/bcd/ext/eigen/Eigen/src/Core/Transpositions.h

.include <bsd.port.mk>

PATCH_ARGS+=	-l
