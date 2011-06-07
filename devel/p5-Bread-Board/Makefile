# New ports collection makefile for:	p5-Bread-Board
# Date created:		2011-05-31
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bread-Board
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A solderless way to wire up your application components

RUN_DEPENDS=	p5-Moose>=1.00:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0.05:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Params-Validate>=0.14:${PORTSDIR}/devel/p5-MooseX-Params-Validate
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Bread::Board.3 \
		Bread::Board::BlockInjection.3 \
		Bread::Board::ConstructorInjection.3 \
		Bread::Board::Container.3 \
		Bread::Board::Container::Parameterized.3 \
		Bread::Board::Dependency.3 \
		Bread::Board::Dumper.3 \
		Bread::Board::LifeCycle.3 \
		Bread::Board::LifeCycle::Singleton.3 \
		Bread::Board::LifeCycle::Singleton::WithParameters.3 \
		Bread::Board::Literal.3 \
		Bread::Board::Manual.3 \
		Bread::Board::Manual::Concepts.3 \
		Bread::Board::Manual::Concepts::Advanced.3 \
		Bread::Board::Manual::Concepts::Typemap.3 \
		Bread::Board::Manual::Example.3 \
		Bread::Board::Manual::Example::FormSensible.3 \
		Bread::Board::Manual::Example::LogDispatch.3 \
		Bread::Board::Service.3 \
		Bread::Board::Service::Deferred.3 \
		Bread::Board::Service::Deferred::Thunk.3 \
		Bread::Board::Service::Inferred.3 \
		Bread::Board::Service::WithClass.3 \
		Bread::Board::Service::WithDependencies.3 \
		Bread::Board::Service::WithParameters.3 \
		Bread::Board::SetterInjection.3 \
		Bread::Board::Traversable.3 \
		Bread::Board::Types.3

.include <bsd.port.mk>
