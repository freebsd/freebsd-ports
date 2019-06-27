# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgresql
PORTREVISION=	0

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql95-server

BUILD_DIRS=	config src/include src/interfaces src/port \
		src/bin/pg_dump src/bin/psql src/bin/scripts src/bin/pg_config \
		src/bin/pgbench doc src/makefiles src/test/regress
INSTALL_DIRS=	${BUILD_DIRS}

CLIENT_ONLY=	yes
COMPONENT=	-client
USE_LDCONFIG=	yes
USES=		pkgconfig

.include "${MASTERDIR}/Makefile"
