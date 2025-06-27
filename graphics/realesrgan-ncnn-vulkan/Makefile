PORTNAME=	realesrgan-ncnn-vulkan
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	graphics
# https://github.com/xinntao/Real-ESRGAN-ncnn-vulkan/issues/29
MASTER_SITES=	https://dev.gentoo.org/~slashbeast/distfiles/${PORTNAME}/:models
DISTFILES=	Real-ESRGAN-v0.2.5.0-models.tar.xz:models

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks
WWW=		https://github.com/xinntao/Real-ESRGAN-ncnn-vulkan

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libwebp.so:graphics/webp \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:${OPENMP}c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	xinntao
GH_PROJECT=	Real-ESRGAN-ncnn-vulkan
GH_TUPLE=	KhronosGroup:glslang:11.1.0-44-g4afd6917:glslang/src/ncnn/glslang \
		Tencent:ncnn:20220420-5-g6125c9f4:ncnn/src/ncnn
CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ON=	USE_SYSTEM_WEBP
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	models*

.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv6, armv7 yet
OPENMP=		gcc-
.endif

post-patch:
	@${REINPLACE_CMD} -e '/PATHSTR/s,models,${DATADIR}/&,' \
		${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
