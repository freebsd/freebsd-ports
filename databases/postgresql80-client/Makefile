# New ports collection makefile for:	PostgreSQL-client
# Date created:				Wed Aug 25 00:13:57 CEST 2004
# Whom:					Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#
# To depend on postgresql-client, set USE_PGSQL=yes.
# See Mk/bsd.port.mk for more info

PORTNAME=	postgresql
PKGNAMESUFFIX=	-client

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql80-server

BUILD_DIRS=	config src/include src/interfaces src/bin/pg_dump \
		src/bin/psql src/bin/scripts src/bin/pg_config \
		doc src/makefiles
CLIENT_ONLY=	yes
USE_LDCONFIG=	yes

.include "${MASTERDIR}/Makefile"
