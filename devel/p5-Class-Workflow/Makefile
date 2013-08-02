# New ports collection makefile for:	Class-Workflow
# Date created:	   24 January 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Workflow
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight workflow system

BUILD_DEPENDS=	p5-Moose>=0.37:${PORTSDIR}/devel/p5-Moose \
		p5-Set-Object>=1.19:${PORTSDIR}/devel/p5-Set-Object \
		p5-MooseX-Clone>=0.04:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-Data-Compare>=0:${PORTSDIR}/devel/p5-Data-Compare \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::Workflow.3 Class::Workflow::Context.3 \
		Class::Workflow::Cookbook.3 Class::Workflow::Instance.3 \
		Class::Workflow::Instance::Simple.3 Class::Workflow::State.3 \
		Class::Workflow::State::AcceptHooks.3 \
		Class::Workflow::State::AutoApply.3 \
		Class::Workflow::State::Simple.3 \
		Class::Workflow::State::TransitionHash.3 \
		Class::Workflow::State::TransitionSet.3 \
		Class::Workflow::Transition.3 \
		Class::Workflow::Transition::Deterministic.3 \
		Class::Workflow::Transition::Simple.3 \
		Class::Workflow::Transition::Strict.3 \
		Class::Workflow::Transition::Validate.3 \
		Class::Workflow::Transition::Validate::Simple.3 \
		Class::Workflow::Util::Delta.3 Class::Workflow::YAML.3

.include <bsd.port.mk>
