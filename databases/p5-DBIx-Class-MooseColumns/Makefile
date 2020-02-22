# $FreeBSD$

PORTNAME=	DBIx-Class-MooseColumns
PORTVERSION=	0.22
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MENDEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Allow write DBIC add_column definitions as attribute options

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=1.24:devel/p5-Moose \
		p5-namespace-autoclean>=0.09:devel/p5-namespace-autoclean \
		p5-Path-Class>0.16:devel/p5-Path-Class \
		p5-MooseX-NonMoose>=0.17:devel/p5-MooseX-NonMoose \
		p5-IO-All>=0.41:devel/p5-IO-All
TEST_DEPENDS=	p5-Test-Aggregate>=0.363:devel/p5-Test-Aggregate \
		p5-Test-Most>=0.21:devel/p5-Test-Most \
		p5-Test-Differences>=0.4801:devel/p5-Test-Differences \
		p5-Test-Deep>=0.103:devel/p5-Test-Deep \
		p5-Test-DBIx-Class>=0.10:devel/p5-Test-DBIx-Class

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
