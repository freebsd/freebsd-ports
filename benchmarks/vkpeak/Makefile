PORTNAME=	vkpeak
DISTVERSION=	20260112
CATEGORIES=	benchmarks

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Profile Vulkan devices to find their peak capacities
WWW=		https://github.com/nihui/vkpeak

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	nihui
GH_TUPLE=	KhronosGroup:glslang:16.1.0-16-gfe88f421:nglslang/ncnn/glslang \
		Tencent:ncnn:20250916-108-g5d19f66e:ncnn/ncnn
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
