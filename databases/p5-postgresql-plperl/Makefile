# New ports collection makefile for:	PostgreSQL PL/Perl 
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#
POSTGRESQL_PORT?=	databases/postgresql7

PORTNAME=	postgresql
PORTVERSION!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V PORTVERSION
PORTREVISION?=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V MASTER_SITE_SUBDIR
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-plperl
DISTFILES!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V DISTFILES
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	A module for using Perl5 to write SQL functions

RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

MD5_FILE=	${.CURDIR}/../../${POSTGRESQL_PORT}/distinfo

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl

MAKE_ARGS+=	-C src/pl/plperl
MAKEFILE=	GNUmakefile

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
