# $FreeBSD$

PORTNAME=	DBIx-Skinny-Pager
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of resultset pager for DBIx::Skinny

RUN_DEPENDS=	\
	p5-DBIx-Skinny>=0.0729:databases/p5-DBIx-Skinny \
	p5-Data-Page>0:databases/p5-Data-Page \
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-UseAllModules>=0:devel/p5-Test-UseAllModules \
		p5-Test-Deep>0:devel/p5-Test-Deep \
		p5-Test-Differences>=0:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
