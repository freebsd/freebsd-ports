# $FreeBSD$

PORTNAME=	AnyEvent-DBD-Pg
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for AnyEvent interface to DBD::Pg async interface

BUILD_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-DBD-Pg>0:databases/p5-DBD-Pg \
		p5-DBI>0:databases/p5-DBI \
		p5-common-sense>=3:devel/p5-common-sense
RUN_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-DBD-Pg>0:databases/p5-DBD-Pg \
		p5-DBI>0:databases/p5-DBI \
		p5-common-sense>=3:devel/p5-common-sense
TEST_DEPENDS=	p5-lib-abs>=0.90:devel/p5-lib-abs

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
