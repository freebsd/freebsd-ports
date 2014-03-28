# Created by: chinsan
# $FreeBSD$

PORTNAME=	MooseX-Storage
PORTVERSION=	0.46
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Serialization framework for Moose classes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-Any>=1.15:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Moose>=0.99:${PORTSDIR}/devel/p5-Moose \
		p5-String-RewritePrefix>=0.004:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-JSON>=0.06:${PORTSDIR}/devel/p5-Test-JSON \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Without-Module>=0:${PORTSDIR}/devel/p5-Test-Without-Module \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
