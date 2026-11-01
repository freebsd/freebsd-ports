PORTNAME=	taisei
DISTVERSION=	1.4.6
CATEGORIES=	games
MASTER_SITES=	https://github.com/taisei-project/taisei/releases/download/v${DISTVERSION}/

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Open source Touhou Project fan game (bullet hell shoot'em up)
WWW=		https://taisei-project.org/ \
		https://github.com/taisei-project/taisei

LICENSE=	CC-BY-4.0 CC0-1.0 MIT PD
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	cglm>0:math/cglm
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libopusfile.so:audio/opusfile \
		libpng16.so:graphics/png \
		libunibreak.so:textproc/libunibreak \
		libwebpdecoder.so:graphics/webp \
		libzstd.so:archivers/zstd

USES=		compiler:c11 desktop-file-utils gettext-tools:build meson \
		pkgconfig python:build sdl shared-mime-info shebangfix ssl \
		tar:xz
USE_SDL=	sdl3

SHEBANG_FILES=	scripts/*.py

# - package_data=disabled installs the game data as loose files under
#   DATADIR instead of a zstd-compressed zip, so py-backports.zstd is
#   not needed at build time
# - LTO causes a crash during the stage 3 boss fight:
#   https://github.com/taisei-project/taisei/issues/378
# - shader_transpiler_dxbc is Windows only, but must be disabled
#   explicitly because USES=meson sets auto_features=enabled
# - allocator=libc: use jemalloc from libc instead of mimalloc
MESON_ARGS=	--wrap-mode=nofallback \
		-Dallocator=libc \
		-Db_lto=false \
		-Db_pch=false \
		-Ddefault_library=shared \
		-Ddeveloper=false \
		-Dforce_vendored_shader_tools=false \
		-Dgamemode=disabled \
		-Dinstall_freedesktop=enabled \
		-Dinstall_macos_bundle=disabled \
		-Dinstall_relocatable=disabled \
		-Dkoishi:default_library=static \
		-Dpackage_data=disabled \
		-Dshader_transpiler_dxbc=disabled \
		-Dtests=disabled \
		-Duse_libcrypto=enabled \
		-Duse_libpng=enabled \
		-Dvalidate_glsl=disabled

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS GLES
OPTIONS_DEFAULT=	GLES

GLES_DESC=	OpenGL ES 3.0 and SDL GPU renderers (shader transpiler)

DOCS_BUILD_DEPENDS=	rst2html5:textproc/py-docutils@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
DOCS_MESON_ENABLED=	docs

GLES_BUILD_DEPENDS=	glslang>0:graphics/glslang
GLES_LIB_DEPENDS=	libspirv-cross-c-shared.so:graphics/spirv-cross

# glslang is located via its CMake package config
GLES_USES=		cmake:indirect
GLES_MESON_ENABLED=	shader_transpiler
GLES_MESON_ON=		-Dr_gles30=enabled -Dr_sdlgpu=enabled
GLES_MESON_OFF=		-Dr_gles30=disabled -Dr_sdlgpu=disabled

.include <bsd.port.mk>
