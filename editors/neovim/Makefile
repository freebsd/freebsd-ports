# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	neovim
PORTVERSION=	0.0.0.201507060407
CATEGORIES=	editors
MASTER_SITES=	GH

MAINTAINER=	antont@inbox.lv
COMMENT=	Next generation Vim

LICENSE=	APACHE20

BUILD_DEPENDS=	luajit:${PORTSDIR}/lang/luajit \
		${LUA_MODSHAREDIR}/MessagePack.lua:${PORTSDIR}/devel/lua-MessagePack \
		${LUA_MODLIBDIR}/bit.so:${PORTSDIR}/devel/lua-bitop \
		${LUA_MODLIBDIR}/lpeg.so:${PORTSDIR}/devel/lua-lpeg
LIB_DEPENDS=	libunibilium.so:${PORTSDIR}/devel/unibilium \
		libvterm.so:${PORTSDIR}/devel/libvterm \
		libtermkey.so:${PORTSDIR}/devel/libtermkey \
		libuv.so:${PORTSDIR}/devel/libuv \
		libmsgpack.so:${PORTSDIR}/devel/msgpack

USES=		cmake lua
USE_GITHUB=	yes
GH_TAGNAME=	1b78ad1

CMAKE_ARGS+=	-DLUA_PRG=${LUA_CMD} \
		-DUSE_BUNDLED_DEPS=OFF

.include <bsd.port.mk>
