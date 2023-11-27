PORTNAME=	Data-Clone
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Polymorphic data cloning
WWW=		https://metacpan.org/release/Data-Clone

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build-XSUtil>=0:devel/p5-Module-Build-XSUtil
TEST_DEPENDS=	p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace \
		p5-Test-Requires>=0.03:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Data/Clone/Clone.so

.include <bsd.port.mk>
