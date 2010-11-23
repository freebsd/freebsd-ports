# New ports collection makefile for:	Devel::Declare::Parser
# Date created:		21 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

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
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Devel::Declare::Interface.3 \
	Devel::Declare::Parser.3 \
	Devel::Declare::Parser::Codeblock.3 \
	Devel::Declare::Parser::Emulate.3 \
	Devel::Declare::Parser::Method.3 \
	Devel::Declare::Parser::Sublike.3

.include <bsd.port.mk>
