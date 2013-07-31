# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moose
PORTVERSION=	2.0802
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Complete modern object system for Perl 5

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Do not add devel/p5-Data-Visitor to TEST_DEPENDS to avoid cyclic dependency in tinderbox
BUILD_DEPENDS=	\
	p5-Class-Load>=0.09:${PORTSDIR}/devel/p5-Class-Load \
	p5-Class-Load-XS>=0.01:${PORTSDIR}/devel/p5-Class-Load-XS \
	p5-Data-OptList>=0.107:${PORTSDIR}/devel/p5-Data-OptList \
	p5-Devel-GlobalDestruction>=0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
	p5-Eval-Closure>=0.04:${PORTSDIR}/devel/p5-Eval-Closure \
	p5-List-MoreUtils>=0.28:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-MRO-Compat>=0.05:${PORTSDIR}/devel/p5-MRO-Compat \
	p5-Package-DeprecationManager>=0.10:${PORTSDIR}/devel/p5-Package-DeprecationManager \
	p5-Package-Stash>=0.32:${PORTSDIR}/devel/p5-Package-Stash \
	p5-Package-Stash-XS>=0.24:${PORTSDIR}/devel/p5-Package-Stash-XS \
	p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util \
	p5-Sub-Exporter>=0.980:${PORTSDIR}/devel/p5-Sub-Exporter \
	p5-Sub-Name>=0.05:${PORTSDIR}/devel/p5-Sub-Name \
	p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
	p5-Try-Tiny>=0.02:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Fatal>=0.001:${PORTSDIR}/devel/p5-Test-Fatal \
	p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-CheckDeps>=0:${PORTSDIR}/devel/p5-Test-CheckDeps

CFLAGS+=	-I.	# mop.h
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure extract

MAN3=	Class::MOP.3 \
	Class::MOP::Attribute.3 \
	Class::MOP::Class.3 \
	Class::MOP::Class::Immutable::Trait.3 \
	Class::MOP::Deprecated.3 \
	Class::MOP::Instance.3 \
	Class::MOP::Method.3 \
	Class::MOP::Method::Accessor.3 \
	Class::MOP::Method::Constructor.3 \
	Class::MOP::Method::Generated.3 \
	Class::MOP::Method::Inlined.3 \
	Class::MOP::Method::Meta.3 \
	Class::MOP::Method::Overload.3 \
	Class::MOP::Method::Wrapped.3 \
	Class::MOP::MiniTrait.3 \
	Class::MOP::Mixin.3 \
	Class::MOP::Mixin::AttributeCore.3 \
	Class::MOP::Mixin::HasAttributes.3 \
	Class::MOP::Mixin::HasMethods.3 \
	Class::MOP::Module.3 \
	Class::MOP::Object.3 \
	Class::MOP::Package.3 \
	Moose.3 \
	Moose::Conflicts.3 \
	Moose::Cookbook.3 \
	Moose::Cookbook::Basics::BankAccount_MethodModifiersAndSubclassing.3 \
	Moose::Cookbook::Basics::BinaryTree_AttributeFeatures.3 \
	Moose::Cookbook::Basics::BinaryTree_BuilderAndLazyBuild.3 \
	Moose::Cookbook::Basics::Company_Subtypes.3 \
	Moose::Cookbook::Basics::DateTime_ExtendingNonMooseParent.3 \
	Moose::Cookbook::Basics::Document_AugmentAndInner.3 \
	Moose::Cookbook::Basics::Genome_OverloadingSubtypesAndCoercion.3 \
	Moose::Cookbook::Basics::HTTP_SubtypesAndCoercion.3 \
	Moose::Cookbook::Basics::Immutable.3 \
	Moose::Cookbook::Basics::Person_BUILDARGSAndBUILD.3 \
	Moose::Cookbook::Basics::Point_AttributesAndSubclassing.3 \
	Moose::Cookbook::Extending::Debugging_BaseClassRole.3 \
	Moose::Cookbook::Extending::ExtensionOverview.3 \
	Moose::Cookbook::Extending::Mooseish_MooseSugar.3 \
	Moose::Cookbook::Legacy::Debugging_BaseClassReplacement.3 \
	Moose::Cookbook::Legacy::Labeled_AttributeMetaclass.3 \
	Moose::Cookbook::Legacy::Table_ClassMetaclass.3 \
	Moose::Cookbook::Meta::GlobRef_InstanceMetaclass.3 \
	Moose::Cookbook::Meta::Labeled_AttributeTrait.3 \
	Moose::Cookbook::Meta::PrivateOrPublic_MethodMetaclass.3 \
	Moose::Cookbook::Meta::Table_MetaclassTrait.3 \
	Moose::Cookbook::Meta::WhyMeta.3 \
	Moose::Cookbook::Roles::ApplicationToInstance.3 \
	Moose::Cookbook::Roles::Comparable_CodeReuse.3 \
	Moose::Cookbook::Roles::Restartable_AdvancedComposition.3 \
	Moose::Cookbook::Snack::Keywords.3 \
	Moose::Cookbook::Snack::Types.3 \
	Moose::Cookbook::Style.3 \
	Moose::Deprecated.3 \
	Moose::Error::Confess.3 \
	Moose::Error::Croak.3 \
	Moose::Error::Default.3 \
	Moose::Error::Util.3 \
	Moose::Exporter.3 \
	Moose::Intro.3 \
	Moose::Manual.3 \
	Moose::Manual::Attributes.3 \
	Moose::Manual::BestPractices.3 \
	Moose::Manual::Classes.3 \
	Moose::Manual::Concepts.3 \
	Moose::Manual::Construction.3 \
	Moose::Manual::Contributing.3 \
	Moose::Manual::Delegation.3 \
	Moose::Manual::Delta.3 \
	Moose::Manual::FAQ.3 \
	Moose::Manual::MOP.3 \
	Moose::Manual::MethodModifiers.3 \
	Moose::Manual::MooseX.3 \
	Moose::Manual::Roles.3 \
	Moose::Manual::Support.3 \
	Moose::Manual::Types.3 \
	Moose::Manual::Unsweetened.3 \
	Moose::Meta::Attribute.3 \
	Moose::Meta::Attribute::Native.3 \
	Moose::Meta::Attribute::Native::Trait.3 \
	Moose::Meta::Attribute::Native::Trait::Array.3 \
	Moose::Meta::Attribute::Native::Trait::Bool.3 \
	Moose::Meta::Attribute::Native::Trait::Code.3 \
	Moose::Meta::Attribute::Native::Trait::Counter.3 \
	Moose::Meta::Attribute::Native::Trait::Hash.3 \
	Moose::Meta::Attribute::Native::Trait::Number.3 \
	Moose::Meta::Attribute::Native::Trait::String.3 \
	Moose::Meta::Class.3 \
	Moose::Meta::Class::Immutable::Trait.3 \
	Moose::Meta::Instance.3 \
	Moose::Meta::Method.3 \
	Moose::Meta::Method::Accessor.3 \
	Moose::Meta::Method::Augmented.3 \
	Moose::Meta::Method::Constructor.3 \
	Moose::Meta::Method::Delegation.3 \
	Moose::Meta::Method::Destructor.3 \
	Moose::Meta::Method::Meta.3 \
	Moose::Meta::Method::Overridden.3 \
	Moose::Meta::Mixin::AttributeCore.3 \
	Moose::Meta::Object::Trait.3 \
	Moose::Meta::Role.3 \
	Moose::Meta::Role::Application.3 \
	Moose::Meta::Role::Application::RoleSummation.3 \
	Moose::Meta::Role::Application::ToClass.3 \
	Moose::Meta::Role::Application::ToInstance.3 \
	Moose::Meta::Role::Application::ToRole.3 \
	Moose::Meta::Role::Attribute.3 \
	Moose::Meta::Role::Composite.3 \
	Moose::Meta::Role::Method.3 \
	Moose::Meta::Role::Method::Conflicting.3 \
	Moose::Meta::Role::Method::Required.3 \
	Moose::Meta::TypeCoercion.3 \
	Moose::Meta::TypeCoercion::Union.3 \
	Moose::Meta::TypeConstraint.3 \
	Moose::Meta::TypeConstraint::Class.3 \
	Moose::Meta::TypeConstraint::DuckType.3 \
	Moose::Meta::TypeConstraint::Enum.3 \
	Moose::Meta::TypeConstraint::Parameterizable.3 \
	Moose::Meta::TypeConstraint::Parameterized.3 \
	Moose::Meta::TypeConstraint::Registry.3 \
	Moose::Meta::TypeConstraint::Role.3 \
	Moose::Meta::TypeConstraint::Union.3 \
	Moose::Object.3 \
	Moose::Role.3 \
	Moose::Spec::Role.3 \
	Moose::Unsweetened.3 \
	Moose::Util.3 \
	Moose::Util::MetaRole.3 \
	Moose::Util::TypeConstraints.3 \
	Moose::Util::TypeConstraints::Builtins.3 \
	Test::Moose.3 \
	metaclass.3 \
	oose.3

post-extract:
	@${PERL} -i -ne 'print unless m,^(check_conflicts),' ${WRKSRC}/Makefile.PL

post-install:
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
