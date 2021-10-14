PORTNAME=	sqlcipher
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
CATEGORIES=	databases

MAINTAINER=	jharris@widomaker.com
COMMENT=	Encrypted SQLite database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libedit libtool pathfix ssl tcl:86,build
CPE_VENDOR=	zetetic
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-tempstore=yes --disable-tcl --disable-readline
CPPFLAGS+=	-DSQLITE_HAS_CODEC
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
CFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
