PORTNAME=	vkpeak
DISTVERSION=	20250531
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
GH_TUPLE=	KhronosGroup:glslang:15.3.0-5-gf3b687b3:nglslang/ncnn/glslang \
		Tencent:ncnn:20250503-33-gebc041cc:ncnn/ncnn
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
