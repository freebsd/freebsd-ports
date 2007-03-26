# ex:ts=8
# Ports collection makefile for:	Pugs::Compiler::Rule
# Date created:			Aug 1, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Pugs-Compiler-Rule
PORTVERSION=	0.21
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/F/FG/FGLOCK
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Compiler for Perl 6 Rules

BUILD_DEPENDS=	p5-Class-InsideOut>=0:${PORTSDIR}/devel/p5-Class-InsideOut \
		p5-Data-Dump-Streamer>=0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-PadWalker>=1.0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Parse-Yapp>=0:${PORTSDIR}/devel/p5-Parse-Yapp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Pugs::Compiler::Regex.3 \
	Pugs::Compiler::RegexPerl5.3 \
	Pugs::Compiler::Rule.3 \
	Pugs::Compiler::Token.3 \
	Pugs::Grammar::Precedence.3 \
	Pugs::Runtime::Match.3 \
	Pugs::Runtime::StrPos.3

.include <bsd.port.mk>
