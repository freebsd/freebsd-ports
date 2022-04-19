PORTNAME=	vkpeak
DISTVERSION=	20220419
CATEGORIES=	benchmarks

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Profile Vulkan devices to find their peak capacities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	nihui
GH_TUPLE=	KhronosGroup:glslang:11.1.0-44-g4afd6917:nglslang/ncnn/glslang \
		Tencent:ncnn:20220419:ncnn/ncnn
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
