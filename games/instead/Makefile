PORTNAME=	instead
PORTVERSION=	3.6.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple Text Adventure, The Interpreter
WWW=		https://instead.syscall.ru/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang iconv pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	instead-hub
GH_TAGNAME=	111f2fa # 3.6.0 + harfbuzz build fix
USE_SDL=	sdl3 image3 ttf3 mixer3

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=		LUAJIT DOCS HARFBUZZ
OPTIONS_DEFAULT=	LUAJIT

LUAJIT_DESC=		Use LuaJIT instead of Lua
HARFBUZZ_DESC=		Build with HarfBuzz for RTL language support

LUAJIT_USES=		luajit
LUAJIT_USES_OFF=	lua:51
LUAJIT_CMAKE_BOOL=	WITH_LUAJIT
HARFBUZZ_CMAKE_BOOL=	WITH_HARFBUZZ
HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

.include <bsd.port.mk>
