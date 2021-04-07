PORTNAME=	vkd3d
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	https://dl.winehq.org/${PORTNAME}/source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Direct3D 12 to Vulkan translation

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/spirv-tools/libspirv.h:graphics/spirv-tools \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libSPIRV-Tools-shared.so:graphics/spirv-tools \
		libvulkan.so:graphics/vulkan-loader
RUN_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

USES=		gmake libtool localbase pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-spirv-tools
TEST_TARGET=	check

# XXX Move to a separate port (a la graphics/vulkan-headers) and maybe make
#     graphics/spirv-tools depend on it as well
USE_GITHUB=	nodefault
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.3:headers/external/spirv-headers
CPPFLAGS+=	-isystem${WRKSRC}/external/spirv-headers/include

post-patch:
	@${REINPLACE_CMD} '/libdl not found/d' ${WRKSRC}/configure

.include <bsd.port.mk>
