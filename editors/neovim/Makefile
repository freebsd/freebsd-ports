# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	neovim
PORTVERSION=	0.1.2
CATEGORIES=	editors
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Next generation Vim

LICENSE=	APACHE20

BUILD_DEPENDS=	${LUA_MODSHAREDIR}/MessagePack.lua:devel/lua-MessagePack \
		${LUA_MODLIBDIR}/bit.so:devel/lua-bitop \
		${LUA_MODLIBDIR}/lpeg.so:devel/lua-lpeg
LIB_DEPENDS=	libunibilium.so:devel/unibilium \
		libvterm.so:devel/libvterm \
		libtermkey.so:devel/libtermkey \
		libluajit-5.1.so:lang/luajit \
		libuv.so:devel/libuv \
		libmsgpack.so:devel/msgpack

USES=		cmake gettext-tools lua gmake pkgconfig
USE_GITHUB=	yes
GH_TAGNAME=	b33c777

CMAKE_ARGS+=	-DLUA_PRG=${LUA_CMD} \
		-DUSE_BUNDLED_DEPS=OFF

.include <bsd.port.mk>
