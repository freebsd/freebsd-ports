# $FreeBSD$

PORTNAME=	libplacebo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	95814b653b71.patch:-p1 # don't check shaderc twice

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Reusable library for GPU-accelerated video/image rendering

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase:ldflags meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	haasn

OPTIONS_DEFINE=	LCMS2 TEST VULKAN
OPTIONS_DEFAULT=LCMS2 SHADERC
OPTIONS_SINGLE=	VULKAN
OPTIONS_SINGLE_VULKAN=	GLSLANG SHADERC

GLSLANG_DESC=		glslang SPIR-V compiler
GLSLANG_BUILD_DEPENDS=	glslang>0:devel/glslang
GLSLANG_MESON_ON=	-Dglslang=enabled
GLSLANG_MESON_OFF=	-Dglslang=disabled
GLSLANG_IMPLIES=	VULKAN

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_MESON_ON=		-Dlcms=enabled
LCMS2_MESON_OFF=	-Dlcms=disabled

SHADERC_DESC=		libshaderc SPIR-V compiler
SHADERC_LIB_DEPENDS=	libshaderc_shared.so:graphics/shaderc
SHADERC_MESON_ON=	-Dshaderc=enabled
SHADERC_MESON_OFF=	-Dshaderc=disabled
SHADERC_IMPLIES=	VULKAN

TEST_MESON_TRUE=	tests

VULKAN_DESC=		Vulkan-based renderer
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_MESON_ON=	-Dvulkan=enabled
VULKAN_MESON_OFF=	-Dvulkan=disabled

post-patch:
# Extract (snapshot) version from port version instead of meson.build
	@${REINPLACE_CMD} "s/version_pretty/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/src/meson.build

pre-install-TEST-on:	do-test

.include <bsd.port.mk>
