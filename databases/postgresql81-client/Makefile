# New ports collection makefile for:	PostgreSQL-client
# Date created:				Wed Nov 2 00:13:57 CET 2005
# Whom:					Palle Girgensohn <girgen@FreeBSD.org>
#
# $FreeBSD$
#
# To depend on postgresql-client, set USE_PGSQL=yes.
# See Mk/bsd.databases.mk for more info

PORTNAME=	postgresql
PKGNAMESUFFIX=	-client
PORTREVISION=	0

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql81-server

BUILD_DIRS=	src/include src/interfaces src/bin doc src/makefiles
CLIENT_ONLY=	yes
INSTALLS_SHLIB=	yes

.include "${MASTERDIR}/Makefile"
