PORTNAME=	sqlcipher
DISTVERSIONPREFIX=	v
DISTVERSION=	4.13.0
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
CONFIGURE_ARGS+=--with-tempstore=yes --disable-tcl --disable-readline --soname=legacy
CPPFLAGS+=	-DSQLITE_HAS_CODEC -DSQLITE_ENABLE_UNLOCK_NOTIFY \
		-DOMIT_MEMLOCK -DSQLITE_ENABLE_COLUMN_METADATA=1 \
		-DSQLITE_EXTRA_INIT=sqlcipher_extra_init \
		-DSQLITE_EXTRA_SHUTDOWN=sqlcipher_extra_shutdown
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB} -lcrypto
CFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}

CONFLICTS_INSTALL=	sqlite3

TEST_TARGET=	test # tests fail to run, see https://github.com/sqlcipher/sqlcipher/issues/527

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
