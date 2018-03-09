# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	posix
DISTVERSIONPREFIX=	release-v
DISTVERSION=	34.0.4
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX layer for Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		lua shebangfix
SHEBANG_FILES=	${WRKSRC}/build-aux/luke
USE_GITHUB=	yes
GH_ACCOUNT=	luaposix
GH_PROJECT=	luaposix

do-build:
	@cd ${WRKSRC} && build-aux/luke \
		version="${PORTVERSION}" \
		PREFIX="${PREFIX}" \
		LUA="${LOCALBASE}/bin/lua${LUA_VER_STR}" \
		LUA_INCDIR="${LUA_INCDIR}" \
		CFLAGS="${CFLAGS}"

do-install:
	cd ${WRKSRC} && build-aux/luke install \
		INST_LIBDIR="${STAGEDIR}${LUA_MODLIBDIR}" \
		INST_LUADIR="${STAGEDIR}${LUA_MODSHAREDIR}"

post-install:
	@${FIND} ${STAGEDIR}${LUA_MODLIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
