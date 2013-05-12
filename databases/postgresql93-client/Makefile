# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$
#
# To depend on postgresql-client, set USE_PGSQL=yes.
# See Mk/bsd.databases.mk for more info

PORTNAME=	postgresql
PORTREVISION=	2
PKGNAMESUFFIX=	-client

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql93-server

BUILD_DIRS=	config src/include src/interfaces src/port \
		src/bin/pg_dump src/bin/psql src/bin/scripts src/bin/pg_config \
		doc src/makefiles
INSTALL_DIRS=	${BUILD_DIRS}

CLIENT_ONLY=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig

.include "${MASTERDIR}/Makefile"
