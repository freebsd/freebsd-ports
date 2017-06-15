# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	100-client

COMMENT=	Multithreaded SQL database (client)

LICENSE+=	LGPL21

MASTERDIR=	${.CURDIR}/../mariadb100-server

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG=	${PREFIX}/lib/mysql

CLIENT_ONLY=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/aclocal/mysql.m4
	${RM} ${STAGEDIR}${PREFIX}/bin/mysqld_safe_helper
	${RM} -r ${STAGEDIR}${PREFIX}/include/mysql/private

.include "${MASTERDIR}/Makefile"
