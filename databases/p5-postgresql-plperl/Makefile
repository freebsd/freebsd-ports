# New ports collection makefile for:	PostgreSQL PL/Perl 
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	databases perl5
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-plperl

MAINTAINER=	girgen@pingpong.net
COMMENT=	A module for using Perl5 to write SQL functions

POSTGRESQL_PORT?=	databases/postgresql7
POSTGRESQL_SUBPORT=YES
.include "../../${POSTGRESQL_PORT}/Makefile"

RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

USE_PERL5=	yes
CONFIGURE_ARGS=	--with-perl

MAKE_ARGS+=	-C src/pl/plperl
MAKEFILE=	GNUmakefile

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
