# New ports collection makefile for:	MooseX-Method-Signatures
# Date created:	   13 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Method-Signatures
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Method declarations with type constraints and no source filter

BUILD_DEPENDS=	p5-Moose>=0.63:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-LazyRequire>=0.03:${PORTSDIR}/devel/p5-MooseX-LazyRequire \
		p5-MooseX-Types>=0.09:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Structured>=0.12:${PORTSDIR}/devel/p5-MooseX-Types-Structured \
		p5-MooseX-Meta-TypeConstraint-ForceCoercion>=0:${PORTSDIR}/devel/p5-MooseX-Meta-TypeConstraint-ForceCoercion \
		p5-namespace-clean>=0.10:${PORTSDIR}/devel/p5-namespace-clean \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-B-Hooks-EndOfScope>=0.07:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Context-Preserve>=0:${PORTSDIR}/devel/p5-Context-Preserve \
		p5-Parse-Method-Signatures>=1.003011:${PORTSDIR}/devel/p5-Parse-Method-Signatures \
		p5-Devel-Declare>=0.005011:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Method::Signatures.3

.include <bsd.port.mk>
