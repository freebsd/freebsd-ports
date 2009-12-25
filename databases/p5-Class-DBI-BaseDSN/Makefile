# New ports collection makefile for:	p5-Class-DBI-BaseDSN
# Date created:	   21 july 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-BaseDSN
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DSN sensitive base class

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI

PERL_MODBUILD=	yes

MAN3=		Class::DBI::BaseDSN.3

.include <bsd.port.mk>
