# Created by: chinsan
# $FreeBSD$

PORTNAME=	Pod-Coverage-Moose
PORTVERSION=	0.04
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pod::Coverage extension for Moose

BUILD_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-Perl6-Junction>=0:${PORTSDIR}/devel/p5-Perl6-Junction \
		p5-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-AttributeHelpers>=0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
