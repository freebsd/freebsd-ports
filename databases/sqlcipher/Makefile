# $FreeBSD$

PORTNAME=	sqlcipher
PORTVERSION=	2.1.1
CATEGORIES=	databases

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Encrypted sqlite database

LICENSE=	BSD

USE_LDCONFIG=	yes
USE_TCL_BUILD=	85
USE_GITHUB=	yes
USES=	pathfix
GH_ACCOUNT=	sqlcipher
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	ee2ce3e
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-tempstore=yes --disable-tcl --disable-readline
CPPFLAGS+=	-DSQLITE_HAS_CODEC
LDFLAGS+=	-lcrypto

CONFLICTS=	sqlite3-3.*

NO_STAGE=	yes
.include <bsd.port.mk>
