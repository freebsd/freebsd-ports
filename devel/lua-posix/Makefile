# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	posix
PORTVERSION=	33.4.0
DISTVERSIONPREFIX=	release-v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX layer for Lua

LICENSE=	MIT

USES=		lua libtool perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LUA_INCLUDE="-I${LUA_INCDIR}" \
		LUA="${LOCALBASE}/bin/lua${LUA_VER_STR}"
CONFIGURE_ARGS=	--disable-silent-rules
MAKE_ARGS=	POSIX_EXTRA_CFLAGS="" POSIX_EXTRA_LDFLAGS=""
INSTALL_TARGET=	install-strip
PORTDOCS=	*

USE_GITHUB=	yes
GH_PROJECT=	luaposix
GH_ACCOUNT=	luaposix

DOCSDIR=	${PREFIX}/share/doc/luaposix

PLIST_FILES=	%%LUA_MODLIBDIR%%/posix.so \
		%%LUA_MODSHAREDIR%%/posix/_argcheck.lua \
		%%LUA_MODSHAREDIR%%/posix/compat.lua \
		%%LUA_MODSHAREDIR%%/posix/deprecated.lua \
		%%LUA_MODSHAREDIR%%/posix/init.lua \
		%%LUA_MODSHAREDIR%%/posix/sys.lua \
		%%LUA_MODSHAREDIR%%/posix/util.lua

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's/\(darwin\*\)|\(freebsd\*\)/\1|dragonfly*|\2/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
