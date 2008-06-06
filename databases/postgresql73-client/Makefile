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
PORTREVISION=	1

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql73-server

BUILD_DIRS=	src/bin/pg_config src/bin/pg_encoding src/bin/psql \
		src/bin/pg_dump src/bin/scripts src/include \
		src/interfaces doc
CLIENT_ONLY=	yes
USE_LDCONFIG=	yes

.include "${MASTERDIR}/Makefile"
