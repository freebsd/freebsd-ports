# $FreeBSD$

PORTNAME=	waifu2x-ncnn-vulkan
DISTVERSION=	20200606
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:devel/glslang \
		vulkan-headers>0:devel/vulkan-headers \
		${LOCALBASE}/lib/libncnn.a:misc/ncnn
LIB_DEPENDS=	libwebp.so:graphics/webp \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:${OPENMP}c++11-lib localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	nihui
CMAKE_SOURCE_PATH=	${WRKSRC}/src
CFLAGS+=	-isystem${LOCALBASE}/include/ncnn
LDFLAGS+=	-lglslang -lHLSL -lOSDependent -lOGLCompiler -lSPIRV -lpthread # from ncnn
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support aarch64, armv6, armv7 yet
OPENMP=		gcc-
.endif

pre-configure:
	@if ${GREP} -q 'NCNN_VULKAN 0' ${LOCALBASE}/include/ncnn/platform.h; then \
		${ECHO_MSG} "${PKGBASE} requires ncnn built with VULKAN option enabled."; \
		return 1; \
	fi

post-extract:
	@${ECHO_CMD} >${WRKSRC}/src/libwebp/CMakeLists.txt
	@${ECHO_CMD} >${WRKSRC}/src/ncnn/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e '/PATHSTR/s,models-,${DATADIR}/&,' \
		${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/models && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
