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
PORTREVISION=	0

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql74-server

BUILD_DIRS=	src/bin src/include src/interfaces doc
CLIENT_ONLY=	yes
INSTALLS_SHLIB=	yes

.include "${MASTERDIR}/Makefile"
