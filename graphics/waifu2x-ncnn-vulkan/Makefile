# $FreeBSD$

PORTNAME=	waifu2x-ncnn-vulkan
DISTVERSION=	20190712-6
DISTVERSIONSUFFIX=	-gb373ce2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:devel/glslang \
		${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
		${LOCALBASE}/lib/libncnn.a:science/ncnn

USES=		cmake compiler:${OPENMP}c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	nihui
CMAKE_SOURCE_PATH=	${WRKSRC}/src
LDFLAGS+=	-lpthread # XXX Convert ncnn to shared library
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.if !exists(/usr/include/omp.h)
# XXX ports/199603 + ports/210337
OPENMP=		gcc-
.endif

pre-configure:
	@if ${GREP} -q 'NCNN_VULKAN.*0' ${LOCALBASE}/include/ncnn/platform.h; then \
		${ECHO_MSG} "${PKGNAME}: Needs ncnn built with VULKAN enabled."; \
		return 1; \
	fi

post-patch:
	@${REINPLACE_CMD} -e '/PATHSTR/s,models-,${DATADIR}/&,' \
		${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/models && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
