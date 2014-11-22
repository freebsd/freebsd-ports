# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	55-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mariadb55-server

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql*-client-* \
			mariadb1[0-9][0-9]-client-* \
			mariadb5[0-46-9]-client-* \
			percona*-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG=	${PREFIX}/lib/mysql

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
