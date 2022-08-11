PORTNAME=	vkd3d
PORTVERSION=	1.4
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

USES=		bison gmake libtool localbase ncurses pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen-doc --with-spirv-tools
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

# Override pkg-config support before https://cgit.freebsd.org/src/commit/?id=396851c20aeb
# but only if devel/ncurses isn't installed
.if !exists(/usr/libdata/pkgconfig/ncurses.pc)
CONFIGURE_ENV+=	NCURSES_CFLAGS=" " NCURSES_LIBS="-lncurses"
.endif

# XXX Move to a separate port (a la graphics/vulkan-headers) and maybe make
#     graphics/spirv-tools depend on it as well
USE_GITHUB=	nodefault
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-168-g5a12186:headers/external/spirv-headers
CPPFLAGS+=	-isystem${WRKSRC}/external/spirv-headers/include

.include <bsd.port.mk>
