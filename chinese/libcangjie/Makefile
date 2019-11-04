# Created by: blubee <hello@blubee.me>
# $FreeBSD$

PORTNAME=		libcangjie
PORTVERSION=		1.3
PORTREVISION=		1
DISTVERSIONPREFIX=	v
CATEGORIES=		chinese

MAINTAINER=	hello@blubee.me
COMMENT=	C library implementing the Cangjie input method

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3		\
		libfreetype.so:print/freetype2          \
		libdbus-1.so:devel/dbus

USES=		autoreconf gmake libtool localbase pkgconfig sqlite xorg

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_XORG=	xi

USE_GITHUB=	yes
GH_ACCOUNT=	Cangjians
GH_PROJECT=	libcangjie

post-install:
	@(${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so)

.include <bsd.port.mk>
