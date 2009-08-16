# New ports collection makefile for:	Class-DBI-Sweet
# Date created:		6 Jul 2005
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Sweet
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extra sweet features for Class::DBI

RUN_DEPENDS=	p5-Class-DBI>=3.0.12:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Data/Page.pm:${PORTSDIR}/databases/p5-Data-Page \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.1+

MAN3=		Class::DBI::Sweet.3 Class::DBI::Sweet::Topping.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,DBD::SQLite,' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
