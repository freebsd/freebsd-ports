PORTNAME=	waifu2x-ncnn-vulkan
DISTVERSION=	20210521
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libwebp.so:graphics/webp \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:${OPENMP}c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	nihui
GH_TUPLE=	KhronosGroup:glslang:11.1.0-44-g4afd6917:glslang/src/ncnn/glslang \
		Tencent:ncnn:20210507-24-g61eb52e2:ncnn/src/ncnn
CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ON=	USE_SYSTEM_WEBP
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
