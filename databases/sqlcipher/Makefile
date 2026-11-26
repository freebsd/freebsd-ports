PORTNAME=	sqlcipher
DISTVERSIONPREFIX=	v
DISTVERSION=	4.20.0
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Encrypted SQLite database
WWW=		https://www.zetetic.net/sqlcipher/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe libtool ssl
CPE_VENDOR=	zetetic
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-readline \
		--dll-basename=libsqlcipher \
		--editline \
		--enable-fts5 \
		--includedir=${PREFIX}/include/sqlcipher \
		--soname=legacy \
		--with-tempstore=yes

CFLAGS+=	-DOMIT_MEMLOCK \
		-DSQLITE_ENABLE_COLUMN_METADATA=1 \
		-DSQLITE_ENABLE_UNLOCK_NOTIFY \
		-DSQLITE_EXTRA_INIT=sqlcipher_extra_init \
		-DSQLITE_EXTRA_SHUTDOWN=sqlcipher_extra_shutdown \
		-DSQLITE_HAS_CODEC \
		-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto -ledit

SOVERSION=	3.54.1
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		TEST
TEST_USES=		tcl:91,build,test
TEST_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR} --with-tclsh=${TCLSH}
TEST_CONFIGURE_OFF=	--disable-tcl
TEST_CFLAGS=		-DSQLCIPHER_TEST

post-install:
	${MV}   ${STAGEDIR}${PREFIX}/bin/sqlite3 \
		${STAGEDIR}${PREFIX}/bin/sqlcipher
	${MV}   ${STAGEDIR}${PREFIX}/lib/libsqlite3.a \
		${STAGEDIR}${PREFIX}/lib/libsqlcipher.a
	${MV}   ${STAGEDIR}${PREFIX}/libdata/pkgconfig/sqlite3.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/sqlcipher.pc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sqlcipher \
		${STAGEDIR}${PREFIX}/lib/libsqlcipher.so.${SOVERSION}

post-install-TEST-on:
	@${RM} -r ${STAGEDIR}${TCL_LIBDIR}

do-test-TEST-on:
	cd ${WRKSRC} && ${MAKE_CMD} testfixture && \
		./testfixture test/sqlcipher.test

.include <bsd.port.mk>
