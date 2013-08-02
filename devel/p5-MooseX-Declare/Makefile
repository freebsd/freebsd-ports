# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MooseX-Declare
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declarative syntax for Moose

BUILD_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Method-Signatures>=0.36:${PORTSDIR}/devel/p5-MooseX-Method-Signatures \
		p5-MooseX-Role-Parameterized>=0.12:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Types>=0.20:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Devel-Declare>=0.005011:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-namespace-clean>=0.11:${PORTSDIR}/devel/p5-namespace-clean \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

MAN3=		MooseX::Declare.3 MooseX::Declare::Context.3 \
		MooseX::Declare::Context::Namespaced.3 \
		MooseX::Declare::Context::Parameterized.3 \
		MooseX::Declare::Context::WithOptions.3 \
		MooseX::Declare::StackItem.3 \
		MooseX::Declare::Syntax::EmptyBlockIfMissing.3 \
		MooseX::Declare::Syntax::Extending.3 \
		MooseX::Declare::Syntax::InnerSyntaxHandling.3 \
		MooseX::Declare::Syntax::Keyword::Class.3 \
		MooseX::Declare::Syntax::Keyword::Clean.3 \
		MooseX::Declare::Syntax::Keyword::Method.3 \
		MooseX::Declare::Syntax::Keyword::MethodModifier.3 \
		MooseX::Declare::Syntax::Keyword::Namespace.3 \
		MooseX::Declare::Syntax::Keyword::Role.3 \
		MooseX::Declare::Syntax::Keyword::With.3 \
		MooseX::Declare::Syntax::KeywordHandling.3 \
		MooseX::Declare::Syntax::MethodDeclaration.3 \
		MooseX::Declare::Syntax::MethodDeclaration::Parameterized.3 \
		MooseX::Declare::Syntax::MooseSetup.3 \
		MooseX::Declare::Syntax::NamespaceHandling.3 \
		MooseX::Declare::Syntax::OptionHandling.3 \
		MooseX::Declare::Syntax::RoleApplication.3 \
		MooseX::Declare::Util.3

.include <bsd.port.mk>
