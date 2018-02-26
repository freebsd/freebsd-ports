# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

DISTVERSION?=	9.2.24
PORTREVISION?=	1
PKGNAMESUFFIX?=	${PORTVERSION:R:S/.//}${COMPONENT}

MAINTAINER?=	pgsql@FreeBSD.org

ICU_PATCHFILE=	pg-9218-icu-2016-08-10.diff.gz

INSTALL_DIRS?=	src/timezone src/backend \
		src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/backend/replication/libpqwalreceiver \
		src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl \
		src/bin/pg_basebackup

DEPRECATED=	PostgreSQL 9.2 support has reached End-of-line. Please upgrade to a later version.
EXPIRATION_DATE=2017-04-05

PG_USER?=	pgsql
PG_GROUP?=	pgsql
PG_UID?=	70

.include "${.CURDIR}/../postgresql10-server/Makefile"
