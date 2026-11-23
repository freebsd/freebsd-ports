PORTNAME=	clx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	lang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Ahead-of-time Lua compiler producing native executables
WWW=		https://github.com/samyeyo/clx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	samyeyo

# clx ships its own lua.h, lauxlib.h and lualib.h, which rename the Lua C API
# to clx_lua_*.  Keep them out of ${PREFIX}/include so they cannot shadow a
# real Lua's headers; the compiler driver is told where they went.
CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=include/clx

PLIST_FILES=	bin/clx \
		include/clx/clx.h \
		include/clx/clx_runtime.h \
		include/clx/clx_simd.h \
		include/clx/lauxlib.h \
		include/clx/lua.h \
		include/clx/lualib.h \
		lib/clx/libclx_base.a \
		lib/clx/libclx_base_size.a \
		lib/clx/libclx_coroutine.a \
		lib/clx/libclx_coroutine_size.a \
		lib/clx/libclx_io.a \
		lib/clx/libclx_io_size.a \
		lib/clx/libclx_math.a \
		lib/clx/libclx_math_size.a \
		lib/clx/libclx_os.a \
		lib/clx/libclx_os_size.a \
		lib/clx/libclx_package.a \
		lib/clx/libclx_package_size.a \
		lib/clx/libclx_string.a \
		lib/clx/libclx_string_size.a \
		lib/clx/libclx_table.a \
		lib/clx/libclx_table_size.a \
		lib/clx/libclx_utf8.a \
		lib/clx/libclx_utf8_size.a \
		lib/libclx.a \
		lib/libclx_capi.a \
		lib/libclx_capi_size.a \
		lib/libclx_lua.a \
		lib/libclx_size.a

.include <bsd.port.mk>
