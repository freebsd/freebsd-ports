# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Carp-REPL
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TSIBLEY
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

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
