# New ports collection makefile for:	PostgreSQL PL/Perl 
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql-plperl
CATEGORIES=	databases perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	girgen@pingpong.net

POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../postgresql7/Makefile>

RUN_DEPENDS=	postgres:${PORTSDIR}/databases/postgresql7

USE_PERL5=	yes
CONFIGURE_ARGS=	--with-perl

MAKE_ARGS+=	-C src/pl/plperl
MAKEFILE=	GNUmakefile

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
