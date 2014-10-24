# $FreeBSD$

PORTNAME=	sqlcipher
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	jharris@widomaker.com
COMMENT=	Encrypted SQLite database

LICENSE=	BSD3CLAUSE

USE_LDCONFIG=	yes
USE_GITHUB=	yes
USES=		libtool pathfix tcl:85,build

GH_ACCOUNT=	sqlcipher
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	ee2ce3e
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-tempstore=yes --disable-tcl --disable-readline
CPPFLAGS+=	-DSQLITE_HAS_CODEC
LDFLAGS+=	-lcrypto

CONFLICTS=	sqlite3-3.*

.include <bsd.port.mk>
