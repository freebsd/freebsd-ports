# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MooseX-Traits
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose eXtension to automatically apply roles at object creation time

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
