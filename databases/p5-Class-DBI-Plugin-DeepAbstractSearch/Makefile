# New ports collection makefile for:	Class-DBI-Plugin-DeepAbstractSearch
# Date created:		2011-02-15
# Whom:			milki <milki@rescomp.berkeley.edy>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-DeepAbstractSearch
PORTVERSION=	0.08
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SRIHA
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Provides deep_search_where() for Class::DBI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-DBI>=0.96:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Class-DBI-Plugin>=0.02:${PORTSDIR}/databases/p5-Class-DBI-Plugin \
		p5-SQL-Abstract>=1.18:${PORTSDIR}/databases/p5-SQL-Abstract

TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

PERL_CONFIGURE=	yes
MAN3=		Class::DBI::Plugin::DeepAbstractSearch.3

.include <bsd.port.mk>
