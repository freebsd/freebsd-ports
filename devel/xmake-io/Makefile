PORTNAME=	xmake-io
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.9
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pericycle.cc@gmail.com
COMMENT=	Cross-platform build utility based on Lua
WWW=		https://xmake.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libsv.so:devel/sv \
		libtbox.so:devel/tbox

USES=		gmake lua:54 luajit pkgconfig readline
USE_GITHUB=	yes
GH_PROJECT=	xmake
GH_TUPLE=	tboox:tbox:914bd30a5f6faca7a749e7956630dfc6caece0b9:tbox/core/src/tbox/tbox

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--external=yes

.include <bsd.port.mk>
