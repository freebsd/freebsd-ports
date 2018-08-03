# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libubox
PORTVERSION=	20180803
CATEGORIES=	devel

MAINTAINER=	mm@FreeBSD.org
COMMENT=	C utility functions for OpenWrt

LICENSE=	GPLv2

USES=		cmake lua:51 tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	mmatuska
GH_TAGNAME=	c83a84af

CMAKE_ARGS+=	-DLUAPATH="${LUA_MODLIBDIR}"

.include <bsd.port.mk>
