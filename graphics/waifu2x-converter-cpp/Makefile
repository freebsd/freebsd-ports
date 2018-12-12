# $FreeBSD$

PORTNAME=	waifu2x-converter-cpp
DISTVERSION=	1.0.0-410
DISTVERSIONSUFFIX=	-g5e5ac35
PORTREVISION=	8
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
LIB_DEPENDS=	libopencv_highgui.so:graphics/opencv \
		libopencv_imgproc.so:graphics/opencv-core

USE_GITHUB=	yes
GH_ACCOUNT=	tanakamura

USES=		cmake compiler:c++11-lib dos2unix
DOS2UNIX_GLOB=	*.cpp *.hpp
CMAKE_ARGS=	-DOPENCV_PREFIX:PATH="${LOCALBASE}" \
		-DOpenCL_LIBRARY:FILEPATH="${LOCALBASE}/lib/libOpenCL.so"
CMAKE_ON=	INSTALL_MODELS
CFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (opencv deps)
TEST_TARGET=	test ARGS="-V"
USE_LDCONFIG=	yes
PLIST_FILES=	bin/${PORTNAME} \
		include/w2xconv.h \
		lib/libw2xc.so
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS SIMD
OPTIONS_DEFAULT=SIMD

DOCS_CMAKE_BOOL=INSTALL_DOCS
SIMD_CMAKE_OFF=	-DARMOPT:BOOL=false -DX86OPT:BOOL=false

post-patch:
	@${REINPLACE_CMD} -e '/Darwin/,/FLAGS_RELEASE/d' \
		-e 's,".*\(-m[^[:space:]]*\).*","\1",' \
		-e 's/$${TS}/${DISTVERSIONFULL}/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
