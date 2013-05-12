# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

DISTVERSION?=	9.3beta1
PORTREVISION=	0
PKGNAMESUFFIX?=	-server

MAINTAINER?=	pgsql@FreeBSD.org

BUILD_DIRS?=	src/timezone src/backend src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/backend/replication/libpqwalreceiver \
		src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl
INSTALL_DIRS?=	${BUILD_DIRS}

.if defined(CLIENT_ONLY)
MAN1=		pg_basebackup.1 pg_isready.1 pg_xlogdump.1

MAN3=		# no MAN3 for 9.0 only

MAN7=		ALTER_COLLATION.7 ALTER_EVENT_TRIGGER.7 ALTER_EXTENSION.7 \
		ALTER_FOREIGN_TABLE.7 ALTER_MATERIALIZED_VIEW.7 ALTER_RULE.7 \
		CREATE_COLLATION.7 CREATE_EVENT_TRIGGER.7 CREATE_EXTENSION.7 \
		CREATE_FOREIGN_TABLE.7 CREATE_MATERIALIZED_VIEW.7 DROP_COLLATION.7 \
		DROP_EVENT_TRIGGER.7 DROP_EXTENSION.7 DROP_FOREIGN_TABLE.7 \
		DROP_MATERIALIZED_VIEW.7 REFRESH_MATERIALIZED_VIEW.7 SECURITY_LABEL.7

.endif

.include "${.CURDIR}/../postgresql92-server/Makefile"
