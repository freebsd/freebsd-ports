# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Specio
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Type constraints and coercions for Perl

LICENSE=	ART20

BUILD_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Devel-PartialDump>=0:${PORTSDIR}/devel/p5-Devel-PartialDump \
		p5-Eval-Closure>=0:${PORTSDIR}/devel/p5-Eval-Closure \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-List-AllUtils>=0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Params-Validate>=0:${PORTSDIR}/devel/p5-MooseX-Params-Validate \
		p5-MooseX-SemiAffordanceAccessor>=0:${PORTSDIR}/devel/p5-MooseX-SemiAffordanceAccessor \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Throwable>=0:${PORTSDIR}/devel/p5-Throwable \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USE_PERL5=	configure
USES=		perl5

MAN3=		Specio.3 \
		Specio::Coercion.3 \
		Specio::Constraint::AnyCan.3 \
		Specio::Constraint::AnyDoes.3 \
		Specio::Constraint::AnyIsa.3 \
		Specio::Constraint::Enum.3 \
		Specio::Constraint::ObjectCan.3 \
		Specio::Constraint::ObjectDoes.3 \
		Specio::Constraint::ObjectIsa.3 \
		Specio::Constraint::Parameterizable.3 \
		Specio::Constraint::Parameterized.3 \
		Specio::Constraint::Role::CanType.3 \
		Specio::Constraint::Role::DoesType.3 \
		Specio::Constraint::Role::Interface.3 \
		Specio::Constraint::Role::IsaType.3 \
		Specio::Constraint::Simple.3 \
		Specio::Declare.3 \
		Specio::DeclaredAt.3 \
		Specio::Exception.3 \
		Specio::Exporter.3 \
		Specio::Helpers.3 \
		Specio::Library::Builtins.3 \
		Specio::Registry.3 \
		Specio::Role::Inlinable.3

.include <bsd.port.mk>
