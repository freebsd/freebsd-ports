# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	101-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mariadb101-server

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CMAKE_ARGS+=	-DWITHOUT_SERVER=1 -DWITH_WSREP=0
INSTALL_TARGET=	install

USE_LDCONFIG=	${PREFIX}/lib/mysql

CLIENT_ONLY=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/aclocal/mysql.m4
	${RM} -r ${STAGEDIR}${PREFIX}/share/pkgconfig
.	for b in mysql mysqladmin mysqlbinlog mysqlcheck mysqldump \
		mysqlimport mysqlshow mysqlslap
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${b}
.	endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient.so.18
.	for b in dialog.so mysql_clear_password.so 
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/plugin/${b}
.	endfor
	# Fix https://mariadb.atlassian.net/browse/MDEV-9388
	@${REINPLACE_CMD} 's/-l-pthread/-lpthread/' ${STAGEDIR}${PREFIX}/bin/mysql_config

post-install-GSSAPI_NONE:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/plugin/auth_gssapi_client.so

.include "${MASTERDIR}/Makefile"
