# $FreeBSD$

PORTNAME=	Devel-Declare-Parser
PORTVERSION=	0.017
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for higher level interface to Devel-Declare

RUN_DEPENDS=	\
	p5-B-Compiling>=0.02:${PORTSDIR}/devel/p5-B-Compiling \
	p5-B-Hooks-EndOfScope>=0.08:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
	p5-Devel-BeginLift>0:${PORTSDIR}/devel/p5-Devel-BeginLift \
	p5-Devel-Declare>=0.006:${PORTSDIR}/devel/p5-Devel-Declare
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception-LessClever>=0:${PORTSDIR}/devel/p5-Test-Exception-LessClever

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Devel::Declare::Interface.3 \
	Devel::Declare::Parser.3 \
	Devel::Declare::Parser::Codeblock.3 \
	Devel::Declare::Parser::Emulate.3 \
	Devel::Declare::Parser::Method.3 \
	Devel::Declare::Parser::Sublike.3

.include <bsd.port.mk>
