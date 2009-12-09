# New ports collection makefile for:	MooseX-Types-Common
# Date created:				2009-12-09
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-Common
PORTVERSION=	0.001000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A set of commonly-used type constraints that do not ship with Moose

RUN_DEPENDS=	p5-Moose>=0.39:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Types::Common.3 \
		MooseX::Types::Common::Numeric.3 \
		MooseX::Types::Common::String.3

.include <bsd.port.mk>
