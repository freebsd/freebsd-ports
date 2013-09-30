# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mariadb55-server

PKGMESSAGE=	mustnotexist
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

LATEST_LINK=	mariadb55-client

CONFLICTS_INSTALL=	mysql-client-[345].* mariadb-client-5.3.* percona-client-5.*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG=	${PREFIX}/lib/mysql

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
