PORTNAME=	Parse-Distname
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse a distribution name

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker-CPANfile>=0:devel/p5-ExtUtils-MakeMaker-CPANfile
TEST_DEPENDS=	p5-Test-Differences>=0,1:devel/p5-Test-Differences \
		p5-Test-UseAllModules>=0.17:devel/p5-Test-UseAllModules

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
