# New ports collection makefile for:	PostgreSQL PL/Perl 
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	0
CATEGORIES=	databases perl5
PKGNAMESUFFIX=	-plperl

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Write SQL functions for PostgreSQL using Perl5

MASTERDIR=	${.CURDIR}/../postgresql${PGSQL_VER}-server

RUN_DEPENDS=	postgres:${.CURDIR}/../postgresql${PGSQL_VER}-server

DEFAULT_PGSQL_VER?=74

# can't include <bsd.port.pre.mk> in a slave port
# so set these instead:
LOCALBASE?=	${DESTDIR}/usr/local
SED?=		/usr/bin/sed

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | ${SED} -n 's/postmaster.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

USE_PERL5=	yes
CONFIGURE_ARGS=	--with-perl

BUILD_DIRS=	src/pl/plperl
SLAVE_ONLY=	yes

.include "${MASTERDIR}/Makefile"
