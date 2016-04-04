# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	MooseX-Types-DateTimeX
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extensions to MooseX::Types::DateTime::ButMaintained

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTimeX-Easy>=0.085:devel/p5-DateTimeX-Easy \
		p5-Moose>=0.41:devel/p5-Moose \
		p5-MooseX-Types>=0.04:devel/p5-MooseX-Types \
		p5-MooseX-Types-DateTime-ButMaintained>=0.04:devel/p5-MooseX-Types-DateTime-ButMaintained \
		p5-Time-Duration-Parse>=0.06:devel/p5-Time-Duration-Parse \
		p5-namespace-clean>=0.08:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
