# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	neovim
PORTVERSION=	0.1.1
PORTREVISION=	0
CATEGORIES=	editors
MASTER_SITES=	GH

MAINTAINER=	antont@inbox.lv
COMMENT=	Next generation Vim

LICENSE=	APACHE20

BUILD_DEPENDS=	${LUA_MODSHAREDIR}/MessagePack.lua:${PORTSDIR}/devel/lua-MessagePack \
		${LUA_MODLIBDIR}/bit.so:${PORTSDIR}/devel/lua-bitop \
		${LUA_MODLIBDIR}/lpeg.so:${PORTSDIR}/devel/lua-lpeg
LIB_DEPENDS=	libunibilium.so:${PORTSDIR}/devel/unibilium \
		libvterm.so:${PORTSDIR}/devel/libvterm \
		libtermkey.so:${PORTSDIR}/devel/libtermkey \
		libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libuv.so:${PORTSDIR}/devel/libuv \
		libmsgpack.so:${PORTSDIR}/devel/msgpack

USES=		cmake lua gmake
USE_GITHUB=	yes
GH_TAGNAME=	v0.1.1

CMAKE_ARGS+=	-DLUA_PRG=${LUA_CMD} \
		-DUSE_BUNDLED_DEPS=OFF
DISTFILES=	v0.1.1.tar.gz

MASTER_SITE_GITHUB=	https://github.com/neovim/neovim/archive/

.include <bsd.port.mk>
