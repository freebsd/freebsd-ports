PORTNAME=	libplacebo
DISTVERSIONPREFIX=	v
DISTVERSION=	3.120.3
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Reusable library for GPU-accelerated video/image rendering

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase:ldflags meson pkgconfig python:3.6+,build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	haasn
MESON_ARGS=	-Ddemos=false

OPTIONS_DEFINE=	LCMS2 OPENGL TEST VULKAN
OPTIONS_DEFAULT=LCMS2 OPENGL SHADERC
OPTIONS_SINGLE=	VULKAN
OPTIONS_SINGLE_VULKAN=	GLSLANG SHADERC
OPTIONS_SUB=	yes

GLSLANG_DESC=		glslang SPIR-V compiler
GLSLANG_BUILD_DEPENDS=	glslang>0:graphics/glslang
GLSLANG_MESON_ENABLED=	glslang
GLSLANG_IMPLIES=	VULKAN

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_MESON_ENABLED=		lcms

OPENGL_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy
OPENGL_MESON_ENABLED=	opengl

SHADERC_DESC=		libshaderc SPIR-V compiler
SHADERC_LIB_DEPENDS=	libshaderc_shared.so:graphics/shaderc
SHADERC_MESON_ENABLED=	shaderc
SHADERC_IMPLIES=	VULKAN

TEST_MESON_TRUE=	tests

VULKAN_DESC=		Vulkan-based renderer
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
			${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_MESON_ENABLED=	vulkan

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/src/vulkan/utils_gen.py
# Extract (snapshot) version from port version instead of meson.build
	@${REINPLACE_CMD} "s/version_pretty/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/src/meson.build

pre-install-TEST-on:	do-test

.include <bsd.port.mk>
