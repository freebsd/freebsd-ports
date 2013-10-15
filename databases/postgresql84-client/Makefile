# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgresql
PORTREVISION=	0
PKGNAMESUFFIX?=	${DISTVERSION:R:S/.//}${COMPONENT}

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql84-server

BUILD_DIRS=	config src/include src/interfaces src/port \
		src/bin/pg_dump src/bin/psql src/bin/scripts src/bin/pg_config \
		doc src/makefiles
CLIENT_ONLY=	yes
COMPONENT=	-client
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
