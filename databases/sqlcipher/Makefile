# $FreeBSD$

PORTNAME=	sqlcipher
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	jharris@widomaker.com
COMMENT=	Encrypted SQLite database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USE_GITHUB=	yes
USES=		libtool pathfix ssl tcl:86,build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-tempstore=yes --disable-tcl --disable-readline
CPPFLAGS+=	-DSQLITE_HAS_CODEC
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
