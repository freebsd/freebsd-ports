PORTNAME=	TIC-80
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2164
PORTREVISION=	2
CATEGORIES=	emulators games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Fantasy game console
WWW=		https://tic80.com

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libduktape.so:lang/duktape-lib \
		libgif.so:graphics/giflib \
		libhttp_parser.so:www/http-parser \
		libinotify.so:devel/libinotify \
		libpng16.so:graphics/png \
		libsquirrel.so:lang/squirrel \
		libunwind.so:devel/libunwind \
		libuv.so:devel/libuv

# for moonscript
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}

USES=		cmake desktop-file-utils gl localbase:ldflags lua:53 pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	nesbox
GH_TUPLE=	nesbox:blip-buf:330226d9b55ecbeea644e17b5e0f096a165ca07e:blip_buf/vendor/blip-buf \
		tronkko:dirent:c885633e126a3a949ec0497273ec13e2c03e862c:dirent/vendor/dirent \
		wren-lang:wren:4a18fc489f9ea3d253b20dd40f4cdad0d6bb40eb:wren/vendor/wren \
		kuba--:zip:d7df626f3aa457e01669f65e61bf8f484e352941:zip/vendor/zip \
		nesbox:moonscript:17179283012b392bff972ad66231d73bfeec6e90:moonscript/vendor/moonscript \
		cofyc:argparse:0d5f5d0745df14a3f373f7eed85bf524714f4524:argparse/vendor/argparse \
		wasm3:wasm3:a3abb3f2d320994be59dfbe2cdafa8d0b6a8253e:wasm3/vendor/wasm3
USE_GL=		gl glu glut
USE_SDL=	sdl2

# unbundled succesfully
#		albertodemichelis:squirrel:9dcf74f99097898dd5a111c4a55b89d1c4d606c0:squirrel/vendor/squirrel
#		svaarala:duktape-releases:28f915a5381ca3a7dfa22130d08fbc5a16ae5d2f:duktape/vendor/duktape
#		lua:lua:75ea9ccbea7c4886f30da147fb67b693b2624c26:lua/vendor/lua
#		madler:zlib:cacf7f1d4e3d44d871b605da3b647f07d718623f:zlib/vendor/zlib
#		nesbox:giflib:1aa11b06d0025eda77b56aec8254130654d4397b:giflib/vendor/giflib
#		libuv:libuv:9c3d692b3941a2a4171629fb52af2e1029c415e8:libuv/vendor/libuv
#		nodejs:http-parser:ec8b5ee63f0e51191ea43bb0c6eac7bfbff3141d:http_parser/vendor/http-parser
#		glennrp:libpng:dbe3e0c43e549a1602286144d94b0666549b18e6:libpng/vendor/libpng
#		libsdl-org:SDL:b424665e0899769b200231ba943353a5fee1b6b6:sdl2/vendor/sdl2
#		grimfang4:sdl-gpu:e3d350b325a0e0d0b3007f69ede62313df46c6ef:sdl_gpu/vendor/sdl-gpu
#		nesbox:lpeg:73d8614a8dea404cf7bfe25a6e4cea7183dc9fb7:lpeg/vendor/lpeg

# not actually needed
#		smuehlst:circle-stdlib:fdb3c4a948421d47fddab8042a92f980cba43915:circle_stdlib/vendor/circle-stdlib
#		floooh:sokol:487822d82ca79dba7b67718d962e1ba6beef01b2:sokol/vendor/sokol
#		mruby:mruby:0f45836b5954accf508f333f932741b925214471:mruby/vendor/mruby

# the demo carts are built, but don't seem to end up being installed
# mruby: to be decided later; not essential
CMAKE_OFF=	BUILD_DEMO_CARTS BUILD_WITH_MRUBY BUILD_LIBRETRO

OPTIONS_DEFINE=	PRO SDLGPU
OPTIONS_DEFAULT=	SDLGPU
PRO_DESC=	Build PRO Version
SDLGPU_DESC=	Support sdl-gpu through graphics/sdl2_gpu
PRO_CMAKE_BOOL=	BUILD_PRO
SDLGPU_LIB_DEPENDS=	libSDL2_gpu.so:graphics/sdl2_gpu
SDLGPU_CMAKE_BOOL=	BUILD_SDLGPU

.include <bsd.port.mk>
