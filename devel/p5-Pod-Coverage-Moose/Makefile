# Created by: chinsan
# $FreeBSD$

PORTNAME=	Pod-Coverage-Moose
PORTVERSION=	0.07
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pod::Coverage extension for Moose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=2.1300:devel/p5-Moose \
		p5-Pod-Coverage>=0:devel/p5-Pod-Coverage \
		p5-namespace-autoclean>=0.08:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-Role-WithOverloading>=0:devel/p5-MooseX-Role-WithOverloading \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
