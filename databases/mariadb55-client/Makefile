# $FreeBSD$

PORTNAME=	mariadb
PORTREVISION=	1
PKGNAMESUFFIX=	55-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mariadb55-server

PKGMESSAGE=	mustnotexist
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql[0-9][0-9]-client-* mariadb[0-46-9][0-9]-client-* mariadb5.[0-46-9]-client-* percona[0-9][0-9]-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG=	${PREFIX}/lib/mysql

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
