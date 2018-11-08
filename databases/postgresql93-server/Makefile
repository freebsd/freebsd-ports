# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

DISTVERSION?=	9.3.24
PKGNAMESUFFIX?=	${DISTVERSION:R:S/.//}${COMPONENT}

MAINTAINER?=	pgsql@FreeBSD.org

INSTALL_DIRS?=	src/common src/timezone src/backend \
		src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/backend/replication/libpqwalreceiver \
		src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl \
		src/bin/pg_basebackup

ICU_PATCHFILE=	pg-9314-icu-2016-08-10.diff.gz
DEPRECATED=	PostgreSQL-9.3 has reached end-of-life
EXPIRATION_DATE=2018-12-08

PG_USER?=	pgsql
PG_GROUP?=	pgsql
PG_UID?=	70

.include "${.CURDIR}/../postgresql10-server/Makefile"
