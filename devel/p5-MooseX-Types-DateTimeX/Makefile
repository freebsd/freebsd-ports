# New ports collection makefile for:	devel/p5-MooseX-Types-DateTimeX
# Date created:				23 Jun 2009
# Whom:					Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-DateTimeX
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Extensions to MooseX::Types::DateTime::ButMaintained

RUN_DEPENDS=	p5-DateTimeX-Easy>=0.085:${PORTSDIR}/devel/p5-DateTimeX-Easy \
		p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-DateTime-ButMaintained>=0.04:${PORTSDIR}/devel/p5-MooseX-Types-DateTime-ButMaintained \
		p5-Time-Duration-Parse>=0.06:${PORTSDIR}/devel/p5-Time-Duration-Parse \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MooseX::Types::DateTimeX.3

.include <bsd.port.mk>
