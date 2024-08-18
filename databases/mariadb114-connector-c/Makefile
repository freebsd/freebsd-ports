PORTNAME=	mariadb
PKGNAMESUFFIX=	114-connector-c

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX:C/-connector-c/-server/}

LICENSE_FILE?=	${WRKSRC}/COPYING.LIB

PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
