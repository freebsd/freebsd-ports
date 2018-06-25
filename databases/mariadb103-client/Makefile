# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mariadb
PORTREVISION=	0
PKGNAMESUFFIX=	103-client

COMMENT=	Multithreaded SQL database (client)

BROKEN_aarch64=		fails to link: missing sbrk

MASTERDIR=	${.CURDIR}/../mariadb103-server

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
		-e 's|(#define LIBS.*)"\\ $$|\1 -L${PREFIX}/lib "\\|' \
		${WRKSRC}/libmariadb/mariadb_config/mariadb_config.c

post-install:
	${RM} -r ${STAGEDIR}${DATADIR}/policy \
		${STAGEDIR}${PREFIX}/include/mysql/server

post-install-GSSAPI_NONE:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/plugin/auth_gssapi_client.so

.include "${MASTERDIR}/Makefile"
