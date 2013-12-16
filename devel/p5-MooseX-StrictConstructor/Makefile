# Created by: glarkin
# $FreeBSD$

PORTNAME=	MooseX-StrictConstructor
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make your MooseX object constructors blow up on unknown attributes

BUILD_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

MAN3=		MooseX::StrictConstructor.3 \
		MooseX::StrictConstructor::Trait::Class.3 \
		MooseX::StrictConstructor::Trait::Method::Constructor.3

NO_STAGE=	yes
.include <bsd.port.mk>
