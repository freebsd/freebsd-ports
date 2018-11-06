# $FreeBSD$

PORTNAME=	MooseX-Types-PortNumber
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Port number type for Moose classes by the IANA

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Exception>=0.31:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
