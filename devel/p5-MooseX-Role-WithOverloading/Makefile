# New ports collection makefile for:	p5-MooseX-Role-WithOverloading
# Date created:	   			09 Dec, 2009
# Whom:		   			Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Role-WithOverloading
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Roles which support overloading

BUILD_DEPENDS=	p5-Moose>=0.78:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Role::WithOverloading::Meta::Role::Application::ToRole.3 \
		MooseX::Role::WithOverloading::Meta::Role::Composite.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite::ToClass.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::FixOverloadedRefs.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::ToInstance.3 \
		MooseX::Role::WithOverloading.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite::ToRole.3 \
		MooseX::Role::WithOverloading::Meta::Role.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite::ToInstance.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::ToClass.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application.3

.include <bsd.port.mk>
