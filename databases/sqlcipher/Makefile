# $FreeBSD$

PORTNAME=	sqlcipher
PORTVERSION=	3.2.0
CATEGORIES=	databases

MAINTAINER=	jharris@widomaker.com
COMMENT=	Encrypted SQLite database

LICENSE=	BSD3CLAUSE

USE_LDCONFIG=	yes
USE_GITHUB=	yes
USES=		libtool pathfix tcl:86,build

GH_ACCOUNT=	sqlcipher
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	94f5427

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-tempstore=yes --disable-tcl --disable-readline
CPPFLAGS+=	-DSQLITE_HAS_CODEC
LDFLAGS+=	-lcrypto

.include <bsd.port.mk>
