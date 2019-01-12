# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	102-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mariadb102-server

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CMAKE_ARGS+=	-DWITHOUT_SERVER=1 \
		-DCONC_WITH_UNITTEST=0 \
		-DCONC_WITH_MYSQLCOMPAT=1 \
		-DWITH_WSREP=0

USE_LDCONFIG=	${PREFIX}/lib/mysql

CLIENT_ONLY=	yes

post-configure:
	${REINPLACE_CMD} -Ee 's|(#define INCLUDE.*)"$$|\1 -I${PREFIX}/include"|' \
		-e 's|(#define LIBS .*)"$$|\1 -L${PREFIX}/lib"|' \
		${WRKDIR}/.build/libmariadb/mariadb_config/mariadb_config.c

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/aclocal/mysql.m4 \
		${STAGEDIR}${PREFIX}/man/man1/aria* \
		${STAGEDIR}${PREFIX}/man/man1/myisam*
	${RM} -r ${STAGEDIR}${PREFIX}/share/pkgconfig \
		${STAGEDIR}${DATADIR}/policy \
		${STAGEDIR}${PREFIX}/include/mysql/server
	# Fix https://mariadb.atlassian.net/browse/MDEV-9388
	@${REINPLACE_CMD} 's/-l-pthread/-pthread/' ${STAGEDIR}${PREFIX}/bin/mysql_config

post-install-GSSAPI_NONE:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/plugin/auth_gssapi_client.so

.include "${MASTERDIR}/Makefile"
