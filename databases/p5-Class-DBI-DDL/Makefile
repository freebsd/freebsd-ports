# New ports collection makefile for:	p5-Class-DBI-DDL
# Date created:	   18 january 2005
# Whom:		   Daniel Wijnands <daniel@itxl.nl>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-DDL
PORTVERSION=	1.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DDL for Class-DBI

RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		Class::DBI::DDL.3 \
		Class::DBI::DDL::Pg.3

.include <bsd.port.mk>
