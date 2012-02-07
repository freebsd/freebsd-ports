# New ports collection makefile for:	p5-Carp-REPL
# Date created:		2011-05-08
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Carp-REPL
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read-Eval-Print-Loop on die and/or warn

BUILD_DEPENDS=	devel/p5-Data-Dump-Streamer>=0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-Devel-LexAlias>=0:${PORTSDIR}/devel/p5-Devel-LexAlias \
		p5-Devel-REPL>=0:${PORTSDIR}/devel/p5-Devel-REPL \
		p5-Devel-StackTrace-WithLexicals>0:${PORTSDIR}/devel/p5-Devel-StackTrace-WithLexicals \
		p5-Lexical-Persistence>0:${PORTSDIR}/devel/p5-Lexical-Persistence \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	devel/p5-Data-Dump-Streamer>=0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-Devel-LexAlias>=0:${PORTSDIR}/devel/p5-Devel-LexAlias \
		p5-Devel-REPL>=0:${PORTSDIR}/devel/p5-Devel-REPL \
		p5-Devel-StackTrace-WithLexicals>0:${PORTSDIR}/devel/p5-Devel-StackTrace-WithLexicals \
		p5-Lexical-Persistence>0:${PORTSDIR}/devel/p5-Lexical-Persistence \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Expect>=0:${PORTSDIR}/devel/p5-Test-Expect

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=		Carp::REPL.3 Devel::REPL::Plugin::Carp::REPL.3

.include <bsd.port.mk>
