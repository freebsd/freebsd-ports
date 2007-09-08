# New ports collection makefile for:	databases/p5-Class-DBI-Plugin-AbstractCount
# Date created:				01 April 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-AbstractCount
PORTVERSION=	0.07
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Get COUNT(*) results with abstract SQL

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI/Plugin.pm:${PORTSDIR}/databases/p5-Class-DBI-Plugin \
		${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::Plugin::AbstractCount.3

.include <bsd.port.mk>
