# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	104-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX:C/-client/-server/}

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	databases/mytop

.include "${MASTERDIR}/Makefile"
