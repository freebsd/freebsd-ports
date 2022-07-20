PORTNAME=	Code-Perl
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FDALY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Produce Perl code from a tree

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
