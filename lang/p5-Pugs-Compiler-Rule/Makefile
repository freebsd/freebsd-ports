# ex:ts=8
# Ports collection makefile for:	Pugs::Compiler::Rule
# Created by: ijliao
# $FreeBSD$

PORTNAME=	Pugs-Compiler-Rule
PORTVERSION=	0.37
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FGLOCK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compiler for Perl 6 Rules

RUN_DEPENDS=	p5-Cache-Cache>=1.05:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-PadWalker>=1.0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Parse-Yapp>=0:${PORTSDIR}/devel/p5-Parse-Yapp \
		p5-YAML-Syck>=0.60:${PORTSDIR}/textproc/p5-YAML-Syck
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp

USES=		perl5
USE_PERL5=	configure

MAN1=	compile_p6grammar.pl.1
MAN3=	Pugs::Compiler::Regex.3 \
	Pugs::Compiler::Grammar.3 \
	Pugs::Compiler::RegexPerl5.3 \
	Pugs::Compiler::Rule.3 \
	Pugs::Compiler::Token.3 \
	Pugs::Emitter::Grammar::Perl5.3 \
	Pugs::Grammar::Precedence.3 \
	Pugs::Runtime::Match.3 \
	Pugs::Runtime::Regex.3 \
	Pugs::Runtime::StrPos.3 \
    	Pugs::Runtime::Tracer.3

.include <bsd.port.mk>
