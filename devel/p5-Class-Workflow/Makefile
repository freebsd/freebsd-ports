# New ports collection makefile for:	Class-Workflow
# Date created:	   24 January 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Workflow
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Lightweight workflow system

BUILD_DEPENDS=	${SITE_PERL}/Moose.pm:${PORTSDIR}/devel/p5-Moose \
		${SITE_PERL}/${PERL_ARCH}/Set/Object.pm:${PORTSDIR}/devel/p5-Set-Object \
		${SITE_PERL}/Data/Compare.pm:${PORTSDIR}/devel/p5-Data-Compare \
		${SITE_PERL}/${PERL_ARCH}/YAML/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Workflow.3 Class::Workflow::Context.3 \
		Class::Workflow::Environment.3 Class::Workflow::Instance.3 \
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
