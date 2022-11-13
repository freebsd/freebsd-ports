PORTNAME=	vkpeak
DISTVERSION=	20221113
CATEGORIES=	benchmarks

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Profile Vulkan devices to find their peak capacities
WWW=		https://github.com/nihui/vkpeak

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	nihui
GH_TUPLE=	KhronosGroup:glslang:11.9.0-19-g86ff4bca:nglslang/ncnn/glslang \
		Tencent:ncnn:20220729-72-g498ca734:ncnn/ncnn
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
