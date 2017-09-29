# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Util
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moose::Util extensions

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

xBUILD_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-TraitFor-Meta-Class-BetterAnonClassNames>=0.002001:devel/p5-MooseX-TraitFor-Meta-Class-BetterAnonClassNames \
		p5-Sub-Exporter-Progressive>=0:devel/p5-Sub-Exporter-Progressive \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-Test-Moose-More>=0.016:devel/p5-Test-Moose-More \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-aliased>=0:devel/p5-aliased

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
