# $FreeBSD$

PORTNAME=	MooseX-Types-PortNumber
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Port number type for moose classes by The Internet Assigned Numbers Authority (IANA)

BUILD_DEPENDS=	p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.30:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0.13:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.30:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0.13:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		MooseX::Types::PortNumber.3

.include <bsd.port.mk>
