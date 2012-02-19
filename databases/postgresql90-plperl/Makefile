# New ports collection makefile for:	PostgreSQL PL/Perl 
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
CATEGORIES=	databases perl5
PKGNAMESUFFIX=	-plperl

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Write SQL functions for PostgreSQL using Perl5

MASTERDIR=	${.CURDIR}/../../databases/postgresql${WANT_PGSQL_VER}-server

RUN_DEPENDS=	postgres:${PORTSDIR}/databases/postgresql${WANT_PGSQL_VER}-server

WANT_PGSQL_VER?=90

USE_PERL5=	yes
CONFIGURE_ARGS=	--with-perl

BUILD_DIRS=	src/backend src/pl/plperl
INSTALL_DIRS=	src/pl/plperl
SLAVE_ONLY=	yes

.include "${MASTERDIR}/Makefile"
