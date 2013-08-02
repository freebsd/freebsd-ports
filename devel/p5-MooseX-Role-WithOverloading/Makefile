# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Role-WithOverloading
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Roles which support overloading

BUILD_DEPENDS=	p5-Moose>=1.15:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		MooseX::Role::WithOverloading.3 \
		MooseX::Role::WithOverloading::Meta::Role.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite::ToClass.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite::ToInstance.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::Composite::ToRole.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::FixOverloadedRefs.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::ToClass.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::ToInstance.3 \
		MooseX::Role::WithOverloading::Meta::Role::Application::ToRole.3 \
		MooseX::Role::WithOverloading::Meta::Role::Composite.3

.include <bsd.port.mk>
