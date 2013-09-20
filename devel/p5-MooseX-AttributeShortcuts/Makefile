# $FreeBSD$

PORTNAME=	MooseX-AttributeShortcuts
PORTVERSION=	0.017
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	MooseX
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Shorthand for common attribute options

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Types-Common>=0:${PORTSDIR}/devel/p5-MooseX-Types-Common \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	MooseX::AttributeShortcuts.3

NO_STAGE=	yes
.include <bsd.port.mk>
