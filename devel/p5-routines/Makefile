PORTNAME=	routines
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typeable method and function signatures

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Function-Parameters>=2.001003:devel/p5-Function-Parameters \
		p5-Type-Tiny>=1.004004:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Auto>=0.03:devel/p5-Test-Auto

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
