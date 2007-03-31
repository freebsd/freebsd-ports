# ex:ts=8
# Ports collection makefile for:	AI::Prolog
# Date created:			Jul 29, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	AI-Prolog
PORTVERSION=	0.737
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for logic programming

RUN_DEPENDS=	p5-aliased>=0.11:${PORTSDIR}/devel/p5-aliased \
		p5-Clone>=0.15:${PORTSDIR}/devel/p5-Clone \
		p5-Exporter-Tidy>=0.06:${PORTSDIR}/devel/p5-Exporter-Tidy \
		p5-Hash-AsObject>=0.05:${PORTSDIR}/devel/p5-Hash-AsObject \
		p5-Regexp-Common>=2.119:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Test-Differences>=0.47:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0.20:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockModule>=0.04:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-Test-Warn>=0.08:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Text-Balanced>=1.95:${PORTSDIR}/textproc/p5-Text-Balanced \
		p5-Text-Quote>=0.03:${PORTSDIR}/textproc/p5-Text-Quote \
		p5-Term-ReadKey>=2.21:${PORTSDIR}/devel/p5-Term-ReadKey
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=</dev/null

MAN1=	aiprolog.1
MAN3=	AI::Prolog.3 \
	AI::Prolog::Article.3 \
	AI::Prolog::Builtins.3 \
	AI::Prolog::ChoicePoint.3 \
	AI::Prolog::Cookbook.3 \
	AI::Prolog::Engine.3 \
	AI::Prolog::Engine::Primitives.3 \
	AI::Prolog::Introduction.3 \
	AI::Prolog::KnowledgeBase.3 \
	AI::Prolog::Parser.3 \
	AI::Prolog::Parser::PreProcessor.3 \
	AI::Prolog::Parser::PreProcessor::Math.3 \
	AI::Prolog::Term.3 \
	AI::Prolog::Term::Cut.3 \
	AI::Prolog::Term::Number.3 \
	AI::Prolog::TermList.3 \
	AI::Prolog::TermList::Clause.3 \
	AI::Prolog::TermList::Primitive.3 \
	AI::Prolog::TermList::Step.3

.include <bsd.port.mk>
