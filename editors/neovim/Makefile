# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	neovim
PORTVERSION=	0.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

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

USES=		cmake:outsource compiler gettext iconv lua pathfix pkgconfig
USE_GITHUB=	yes

CMAKE_ARGS=	-DLUA_PRG:FILEPATH="${LUA_CMD}" \
		-DCMAKE_INSTALL_MANDIR:PATH="${MANPREFIX}/man" \
		-DDEPS_PREFIX:PATH="${LOCALBASE}"

.include <bsd.port.mk>
