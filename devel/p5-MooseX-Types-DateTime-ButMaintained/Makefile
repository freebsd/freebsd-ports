# New ports collection makefile for:	devel/p5-MooseX-Types-DateTime-ButMaintained
# Date created:				23 Jun 2009
# Whom:					Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-DateTime-ButMaintained
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	DateTime related constraints and coercions for Moose

RUN_DEPENDS=	p5-DateTime>=0.43:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Locale>=0.40:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=0.77:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Olson-Abbreviations>=0:${PORTSDIR}/devel/p5-Olson-Abbreviations \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MooseX::Types::DateTime::ButMaintained.3

.include <bsd.port.mk>
