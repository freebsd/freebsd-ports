# $FreeBSD$

PORTNAME=	Test-postgresql
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of postgresql runner for tests

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite \
	p5-DBI>0:databases/p5-DBI \
	p5-DBD-Pg>0:databases/p5-DBD-Pg
TEST_DEPENDS=	p5-Test-SharedFork>=0.06:devel/p5-Test-SharedFork

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
