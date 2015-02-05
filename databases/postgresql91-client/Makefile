# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgresql
PKGNAMESUFFIX?=	${DISTVERSION:R:S/.//}${COMPONENT}

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql91-server

LIB_DEPENDS=	libedit.so.0:${PORTSDIR}/devel/libedit
BUILD_DIRS=	config src/include src/interfaces src/port \
		src/bin/pg_dump src/bin/psql src/bin/scripts src/bin/pg_config \
		doc src/makefiles
INSTALL_DIRS=	${BUILD_DIRS}

CLIENT_ONLY=	yes
COMPONENT=	-client
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-libedit-preferred

.include "${MASTERDIR}/Makefile"
