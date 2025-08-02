PORTNAME=	waifu2x-ncnn-vulkan
DISTVERSION=	20250802
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks
WWW=		https://github.com/nihui/waifu2x-ncnn-vulkan

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libpng.so:graphics/png \
		libwebp.so:graphics/webp
RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:${OPENMP}c++11-lib jpeg localbase
USE_GITHUB=	yes
GH_ACCOUNT=	nihui
GH_TUPLE=	KhronosGroup:glslang:15.3.0-20-g8cd77a80:glslang/src/ncnn/glslang \
		Tencent:ncnn:20250503-87-gb039b87d:ncnn/src/ncnn
CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ON=	${JPEG PNG WEBP ZLIB:L:S/^/USE_SYSTEM_/}
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv6, armv7 yet
OPENMP=		gcc-
.endif

post-patch:
	@${REINPLACE_CMD} -e '/PATHSTR/s,models-,${DATADIR}/&,' \
		${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/models && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
