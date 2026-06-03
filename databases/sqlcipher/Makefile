PORTNAME=	sqlcipher
DISTVERSIONPREFIX=	v
DISTVERSION=	4.13.0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	jharris@widomaker.com
COMMENT=	Encrypted SQLite database
WWW=		https://www.zetetic.net/sqlcipher/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe libedit libtool localbase:ldflags ssl tcl:86,build
CPE_VENDOR=	zetetic
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-readline \
		--disable-tcl \
		--dll-basename=libsqlcipher \
		--includedir=${PREFIX}/include/sqlcipher \
		--soname=libsqlcipher.so.0 \
		--with-tempstore=yes

TEST_TARGET=	test # tests fail to run, see https://github.com/sqlcipher/sqlcipher/issues/527

CFLAGS+=	-I${OPENSSLINC}
CPPFLAGS+=	-DOMIT_MEMLOCK \
		-DSQLITE_ENABLE_COLUMN_METADATA=1 \
		-DSQLITE_ENABLE_UNLOCK_NOTIFY \
		-DSQLITE_EXTRA_INIT=sqlcipher_extra_init \
		-DSQLITE_EXTRA_SHUTDOWN=sqlcipher_extra_shutdown \
		-DSQLITE_HAS_CODEC
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto

post-install:
	${MV}   ${STAGEDIR}${PREFIX}/bin/sqlite3 \
		${STAGEDIR}${PREFIX}/bin/sqlcipher
	${MV}   ${STAGEDIR}${PREFIX}/lib/libsqlite3.a \
		${STAGEDIR}${PREFIX}/lib/libsqlcipher.a
	${MV}   ${STAGEDIR}${PREFIX}/libdata/pkgconfig/sqlite3.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/sqlcipher.pc
	${MV}   ${STAGEDIR}${PREFIX}/share/man/man1/sqlite3.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/sqlcipher.1
	${REINPLACE_CMD} -i "" -e 's|sqlite3|sqlcipher|g; \
		s|/usr/local/include|$${prefix}/include|g' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/sqlcipher.pc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
