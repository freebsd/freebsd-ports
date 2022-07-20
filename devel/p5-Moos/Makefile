PORTNAME=	Moos
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moo s{imple,peedy,ingle}

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-XSAccessor>=1.07:devel/p5-Class-XSAccessor \
		p5-Role-Tiny>=1.002.000:devel/p5-Role-Tiny
TEST_DEPENDS=	p5-Sub-Identify>=0.04:devel/p5-Sub-Identify \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
