# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

DISTVERSION?=	8.2.23
PORTREVISION?=	0
PKGNAMESUFFIX?=	-server

MAINTAINER?=	crees@FreeBSD.org

DEPRECATED=	No longer supported by upstream-- upgrade to later version
EXPIRATION_DATE=2012-03-27

CONFIGURE_ARGS+=--with-docdir=${DOCSDIR}

ICU_PATCHFILE=	# no ICU patch for 8.2; this inhibits ICU option display
BUILD_DIRS?=	src/port src/timezone src/backend src/backend/utils/mb/conversion_procs \
		src/bin/initdb src/bin/ipcclean src/bin/pg_ctl src/bin/pg_controldata \
		src/bin/pg_resetxlog src/pl

.if defined(CLIENT_ONLY)
MAN1=		ipcclean.1
MAN7=		# empty; no extra manpages over default
.endif

.if !defined(NO_BUILD)
pre-build:
	@ cd ${WRKSRC}/src/backend ;\
	    ${GMAKE} ../../src/include/parser/parse.h \
		     ../../src/include/utils/fmgroids.h
.endif

.include "${.CURDIR}/../postgresql84-server/Makefile"
