PORTNAME=	libplacebo
DISTVERSIONPREFIX=	v
DISTVERSION=	7.351.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Reusable library for GPU-accelerated video/image rendering
WWW=		https://code.videolan.org/videolan/libplacebo

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase:ldflags meson pkgconfig python:build
USE_GITHUB=	nodefault
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	videolan
GH_TUPLE=	fastfloat:fast_float:v5.2.0:fast_float/3rdparty/fast_float
MESON_ARGS=	-Dd3d11=disabled -Dlibdovi=disabled -Ddemos=false

OPTIONS_DEFINE=	LCMS2 LIBUNWIND OPENGL TEST VULKAN XXHASH
OPTIONS_DEFAULT=LCMS2 LIBUNWIND OPENGL SHADERC XXHASH
OPTIONS_SINGLE=	VULKAN
OPTIONS_SINGLE_VULKAN=	GLSLANG SHADERC
OPTIONS_EXCLUDE+=	${ARCH:Naarch64:Namd64:Narmv[67]:Ni386:Npowerpc64:Npowerpc64le:Nx86_64:C/.+/LIBUNWIND/}
OPTIONS_SUB=	yes

GLSLANG_DESC=		glslang SPIR-V compiler
GLSLANG_BUILD_DEPENDS=	glslang>0:graphics/glslang
GLSLANG_MESON_ENABLED=	glslang
GLSLANG_IMPLIES=	VULKAN

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_MESON_ENABLED=		lcms

LIBUNWIND_DESC=		Use libunwind for stacktraces
LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_MESON_ENABLED=	unwind

OPENGL_USE=		GITHUB=nodefault
OPENGL_GH_TUPLE=	Dav1dde:glad:v2.0.4:glad/3rdparty/glad
OPENGL_MESON_ENABLED=	opengl

SHADERC_DESC=		libshaderc SPIR-V compiler
SHADERC_LIB_DEPENDS=	libshaderc_shared.so:graphics/shaderc
SHADERC_MESON_ENABLED=	shaderc
SHADERC_IMPLIES=	VULKAN

TEST_MESON_TRUE=	tests

VULKAN_DESC=		Vulkan-based renderer
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
			${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_MESON_ENABLED=	vulkan

XXHASH_DESC=		Faster replacement for internal siphash
XXHASH_BUILD_DEPENDS=	xxhash>0:devel/xxhash
XXHASH_RUN_DEPENDS=	xxhash>0:devel/xxhash # pkg-config
XXHASH_MESON_ENABLED=	xxhash

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/src/vulkan/utils_gen.py
# https://github.com/mesonbuild/meson/issues/7746
	@${REINPLACE_CMD} "s,static:,dirs: '${LOCALBASE}/lib'\, &," \
		${WRKSRC}/src/glsl/meson.build
# Extract (snapshot) version from port version instead of meson.build
	@${REINPLACE_CMD} -e "s/'git'/'${FALSE}'/" \
		-e "s/version_pretty/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/src/meson.build

pre-install-TEST-on:	do-test

.include <bsd.port.mk>
