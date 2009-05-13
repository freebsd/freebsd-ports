# New ports collection makefile for:	MooseX-Declare
# Date created:	   13 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Declare
PORTVERSION=	0.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Declarative syntax for Moose

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Method-Signatures>=0.16:${PORTSDIR}/devel/p5-MooseX-Method-Signatures \
		p5-Devel-Declare>=0.005001:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-B-Hooks-EndOfScope>=0:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean \
		p5-namespace-autoclean>=0.05:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Declare.3 MooseX::Declare::Context.3 \
		MooseX::Declare::Syntax::EmptyBlockIfMissing.3 \
		MooseX::Declare::Syntax::Extending.3 \
		MooseX::Declare::Syntax::InnerSyntaxHandling.3 \
		MooseX::Declare::Syntax::Keyword::Class.3 \
		MooseX::Declare::Syntax::Keyword::Clean.3 \
		MooseX::Declare::Syntax::Keyword::Method.3 \
		MooseX::Declare::Syntax::Keyword::MethodModifier.3 \
		MooseX::Declare::Syntax::Keyword::Role.3 \
		MooseX::Declare::Syntax::KeywordHandling.3 \
		MooseX::Declare::Syntax::MethodDeclaration.3 \
		MooseX::Declare::Syntax::MooseSetup.3 \
		MooseX::Declare::Syntax::NamespaceHandling.3 \
		MooseX::Declare::Syntax::OptionHandling.3 \
		MooseX::Declare::Syntax::RoleApplication.3 \
		MooseX::Declare::Util.3

.include <bsd.port.mk>
