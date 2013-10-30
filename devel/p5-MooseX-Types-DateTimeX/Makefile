# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	MooseX-Types-DateTimeX
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensions to MooseX::Types::DateTime::ButMaintained

RUN_DEPENDS=	p5-DateTimeX-Easy>=0.085:${PORTSDIR}/devel/p5-DateTimeX-Easy \
		p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-DateTime-ButMaintained>=0.04:${PORTSDIR}/devel/p5-MooseX-Types-DateTime-ButMaintained \
		p5-Time-Duration-Parse>=0.06:${PORTSDIR}/devel/p5-Time-Duration-Parse \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
