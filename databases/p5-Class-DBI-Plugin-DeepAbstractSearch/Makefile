# Created by: milki <milki@rescomp.berkeley.edy>
# $FreeBSD$

PORTNAME=	Class-DBI-Plugin-DeepAbstractSearch
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SRIHA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides deep_search_where() for Class::DBI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-DBI>=0.96:databases/p5-Class-DBI \
		p5-Class-DBI-Plugin>=0.02:databases/p5-Class-DBI-Plugin \
		p5-SQL-Abstract>=1.18:databases/p5-SQL-Abstract
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
