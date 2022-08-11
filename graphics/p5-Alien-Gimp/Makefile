PORTNAME=	Alien-Gimp
PORTVERSION=	0.10
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Encapsulate install info for GIMP

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-ExtUtils-Depends>=0.402:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-IO-All>=0:devel/p5-IO-All
RUN_DEPENDS=	gimp-app>=2.8.0:graphics/gimp-app
TEST_DEPENDS=	p5-Inline-C>=0.67:devel/p5-Inline-C \
		p5-Inline>=0.78:devel/p5-Inline

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
