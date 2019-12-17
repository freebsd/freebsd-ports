# $FreeBSD$

PORTNAME=	waifu2x-converter-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.3
PORTREVISION=	2
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	858fed6eac1d.patch:-p1 # https://github.com/DeadSix27/waifu2x-converter-cpp/pull/215
PATCHFILES+=	318c254dde60.patch:-p1 # https://github.com/DeadSix27/waifu2x-converter-cpp/pull/216
PATCHFILES+=	728310bb4630.patch:-p1 # https://github.com/DeadSix27/waifu2x-converter-cpp/pull/217

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/include/picojson_LICENSE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
LIB_DEPENDS=	libopencv_imgcodecs.so:graphics/opencv \
		libopencv_imgproc.so:graphics/opencv-core

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	DeadSix27
CMAKE_ARGS=	-DOPENCV_PREFIX:PATH="${LOCALBASE}" \
		-DOpenCL_LIBRARY:FILEPATH="${LOCALBASE}/lib/libOpenCL.so"
CMAKE_ON=	INSTALL_MODELS ENABLE_TESTS
TEST_TARGET=	test
PLIST_FILES=	bin/${PORTNAME} \
		include/w2xconv.h \
		lib/libw2xc.so
PORTDATA=	*

.if exists(/usr/lib/libc++fs.a)
# XXX Remove after FreeBSD 11.3/12.1 EOL
CMAKE_ARGS+=	-DFILE_SYSTEM_LIB:STRING=c++fs
.elif !exists(/usr/include/c++/v1/filesystem) && exists(/usr/lib/libc++experimental.a)
# XXX Remove after FreeBSD 12.0 EOL
CMAKE_ARGS+=	-DFILE_SYSTEM_LIB:STRING=c++experimental
.endif

OPTIONS_DEFINE=	SIMD
OPTIONS_DEFAULT=SIMD

SIMD_CMAKE_OFF=	-DARMOPT:BOOL=false -DPPCOPT:BOOL=false -DX86OPT:BOOL=false

post-patch:
	@${REINPLACE_CMD} -e '/Darwin/,/FLAGS_RELEASE/d' \
		-e 's,".*\(-m[^[:space:]]*\).*","\1",' \
		-e "s/\$${TS}/`${AWK} '/TIMESTAMP/ { print \$$3 }' ${DISTINFO_FILE}`/" \
		-e '/find_program/s/git/&_disabled/' \
		-e '/GIT_BRANCH/s/null/master/' \
		-e '/GIT_COMMIT_HASH/s/000000/${DISTVERSIONSUFFIX:U&:S/^-g//}/' \
		-e '/GIT_TAG/s/v0\.0\.0/${DISTVERSIONFULL:C/-.*//}/' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's,models_rgb,${WRKSRC}/&,' ${WRKSRC}/w32-apps/runtest.c

.include <bsd.port.mk>
