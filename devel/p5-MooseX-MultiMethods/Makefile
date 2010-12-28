# New ports collection makefile for:	devel/p5-MooseX-MultiMethods
# Date created:				Dec 28, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-MultiMethods
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Multi Method Dispatch based on Moose type constraints

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-aliased>0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Devel-Declare>=0.004000:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-MooseX-Types-VariantTable>=0.03:${PORTSDIR}/devel/p5-MooseX-Types-VariantTable \
		p5-MooseX-Method-Signatures>=0.29:${PORTSDIR}/devel/p5-MooseX-Method-Signatures \
		p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		MooseX::MultiMethods.3 \
		MooseX::MultiMethods::Meta::Method.3

.include <bsd.port.mk>
