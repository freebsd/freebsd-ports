PORTNAME=	sqlcipher
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.1
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	jharris@widomaker.com
COMMENT=	Encrypted SQLite database
WWW=		https://www.zetetic.net/sqlcipher/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe libedit libtool ssl tcl:86,build
CPE_VENDOR=	zetetic
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-tempstore=yes --disable-tcl --disable-readline
CPPFLAGS+=	-DSQLITE_HAS_CODEC -DSQLITE_ENABLE_UNLOCK_NOTIFY \
		-DSQLITE_ENABLE_COLUMN_METADATA=1
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
CFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}

TEST_TARGET=	test # tests fail to run, see https://github.com/sqlcipher/sqlcipher/issues/527

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
