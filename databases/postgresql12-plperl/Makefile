# Created by: Palle Girgensohn <girgen@partitur.se>

PORTNAME=	postgresql
# Keep the ?=, this port is used as master by the other plperl.
PORTREVISION?=	0
CATEGORIES=	databases perl5
PKGNAMESUFFIX?=	${WANT_PGSQL_VER:S/.//}${COMPONENT}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Write SQL functions for PostgreSQL using Perl5

RUN_DEPENDS=	postgres:databases/postgresql${WANT_PGSQL_VER:S/.//}-server

MASTERDIR=	${.CURDIR}/../../databases/postgresql${WANT_PGSQL_VER:S/.//}-server

WANT_PGSQL_VER?=12

USES+=		perl5 readline
CONFIGURE_ARGS=	--with-perl

BUILD_DIRS=	src/backend ${INSTALL_DIRS}
INSTALL_DIRS?=	src/pl/plperl contrib/hstore_plperl contrib/jsonb_plperl
SLAVE_ONLY=	yes
COMPONENT=	-plperl

# this port fails to build in parallel
MAKE_JOBS_UNSAFE=	yes

.include "${MASTERDIR}/Makefile"
