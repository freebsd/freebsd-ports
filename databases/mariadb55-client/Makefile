# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	55-client

COMMENT=	Multithreaded SQL database (client)

LICENSE+=	LGPL21

MASTERDIR=	${.CURDIR}/../mariadb55-server

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mariadb5[0-46-9]-client-* \
			mariadb1*-client-* \
			mysql*-client-* \
			percona*-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1
CLIENT_ONLY=	yes

USES+=		ncurses readline


post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/mysqld_safe_helper
	${RM} -r ${STAGEDIR}${PREFIX}/include/mysql/private

.include "${MASTERDIR}/Makefile"
