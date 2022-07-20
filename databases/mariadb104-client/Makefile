PORTNAME=	mariadb
PKGNAMESUFFIX=	104-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX:C/-client/-server/}

PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	databases/mytop

.include "${MASTERDIR}/Makefile"
