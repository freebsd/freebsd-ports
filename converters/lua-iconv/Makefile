PORTNAME=	iconv
PORTVERSION=	7
PORTREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	https://github.com/downloads/ittner/lua-iconv/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	lua-${PORTNAME}-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Iconv binding for Lua 5

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig iconv lua:module

PLIST_FILES=	${LUA_MODLIBDIR}/iconv.so
CFLAGS+=	`pkgconf --cflags lua-${LUA_VER}` -I${LOCALBASE}/include
MAKE_ARGS=	LUABIN=${LUA_CMD} CFLAGS="${CFLAGS}"
LDFLAGS+=	-shared ${ICONV_LIB} -L${LOCALBASE}/lib
CFLAGS_aarch64=	-fPIC
CFLAGS_amd64=	-fPIC
CFLAGS_armv6=	-fPIC
CFLAGS_armv7=	-fPIC
CFLAGS_i386=	-fPIC
CFLAGS_powerpc=	-fPIC
CFLAGS_riscv64=	-fPIC

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/iconv.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
