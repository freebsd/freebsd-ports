# New ports collection makefile for:	p5-Test-Parser
# Date created:		2006-08-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Parser
PORTVERSION=	1.3.1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Parsing log files from test runs, and displays in an XML syntax

RUN_DEPENDS=	${SITE_PERL}/Chart/Graph/Gnuplot.pm:${PORTSDIR}/graphics/p5-Chart-Graph \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig

PERL_CONFIGURE=	yes

MAN3=		Test::Metadata.3 Test::Parser.3 Test::Parser::KernelBuild.3 \
		Test::Parser::LHCS.3 Test::Parser::LTP.3 \
		Test::Parser::NewPyNfs.3 Test::Parser::Vmstat.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser

post-patch:
	${FIND} ${WRKSRC}/lib -type f | ${XARGS} ${PERL} -pi -e \
		's/^use (vars|warnings).*$$//g'
.endif

.include <bsd.port.post.mk>
