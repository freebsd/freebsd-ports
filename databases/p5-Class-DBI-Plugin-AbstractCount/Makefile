# New ports collection makefile for:	databases/p5-Class-DBI-Plugin-AbstractCount
# Date created:				01 April 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-AbstractCount
PORTVERSION=	0.08
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Get COUNT(*) results with abstract SQL

BUILD_DEPENDS=	p5-Class-DBI-Plugin>=0.02:${PORTSDIR}/databases/p5-Class-DBI-Plugin \
		p5-Class-DBI>=0.95:${PORTSDIR}/databases/p5-Class-DBI \
		p5-SQL-Abstract>=1.50:${PORTSDIR}/databases/p5-SQL-Abstract
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::Plugin::AbstractCount.3

.include <bsd.port.mk>
