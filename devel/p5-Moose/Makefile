# New ports collection makefile for:	devel/p5-Moose
# Date created:				14 Apr 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Moose
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A complete modern object system for Perl 5

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Class-MOP>=0.59:${PORTSDIR}/devel/p5-Class-MOP \
	p5-Sub-Exporter>=0.972:${PORTSDIR}/devel/p5-Sub-Exporter \
	p5-Filter-Simple>=0:${PORTSDIR}/textproc/p5-Filter-Simple

PERL_CONFIGURE=	5.8.0+

MAN3=	Moose.3 \
	Moose::Cookbook.3 \
	Moose::Cookbook::FAQ.3 \
	Moose::Cookbook::Recipe1.3 \
	Moose::Cookbook::Recipe11.3 \
	Moose::Cookbook::Recipe2.3 \
	Moose::Cookbook::Recipe3.3 \
	Moose::Cookbook::Recipe4.3 \
	Moose::Cookbook::Recipe5.3 \
	Moose::Cookbook::Recipe6.3 \
	Moose::Cookbook::Recipe7.3 \
	Moose::Cookbook::Recipe9.3 \
	Moose::Cookbook::Recipe10.3 \
	Moose::Cookbook::Recipe21.3 \
	Moose::Cookbook::Recipe22.3 \
	Moose::Cookbook::Snack::Keywords.3 \
	Moose::Cookbook::Snack::Types.3 \
	Moose::Cookbook::Style.3 \
	Moose::Cookbook::WTF.3 \
	Moose::Meta::Attribute.3 \
	Moose::Meta::Class.3 \
	Moose::Meta::Instance.3 \
	Moose::Meta::Method.3 \
	Moose::Meta::Method::Accessor.3 \
	Moose::Meta::Method::Augmented.3 \
	Moose::Meta::Method::Constructor.3 \
	Moose::Meta::Method::Destructor.3 \
	Moose::Meta::Method::Overriden.3 \
	Moose::Meta::Role.3 \
	Moose::Meta::Role::Application.3 \
	Moose::Meta::Role::Application::RoleSummation.3 \
	Moose::Meta::Role::Application::ToClass.3 \
	Moose::Meta::Role::Application::ToInstance.3 \
	Moose::Meta::Role::Application::ToRole.3 \
	Moose::Meta::Role::Composite.3 \
	Moose::Meta::Role::Method.3 \
	Moose::Meta::Role::Method::Required.3 \
	Moose::Meta::TypeCoercion.3 \
	Moose::Meta::TypeCoercion::Union.3 \
	Moose::Meta::TypeConstraint.3 \
	Moose::Meta::TypeConstraint::Class.3 \
	Moose::Meta::TypeConstraint::Enum.3 \
	Moose::Meta::TypeConstraint::Parameterizable.3 \
	Moose::Meta::TypeConstraint::Parameterized.3 \
	Moose::Meta::TypeConstraint::Registry.3 \
	Moose::Meta::TypeConstraint::Role.3 \
	Moose::Meta::TypeConstraint::Union.3 \
	Moose::Object.3 \
	Moose::Role.3 \
	Moose::Spec::Role.3 \
	Moose::Util.3 \
	Moose::Util::TypeConstraints.3 \
	Moose::Util::TypeConstraints::OptimizedConstraints.3 \
	Test::Moose.3 \
	oose.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
