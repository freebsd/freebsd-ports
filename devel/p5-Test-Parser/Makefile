# New ports collection makefile for:	p5-Test-Parser
# Date created:		2006-08-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Parser
PORTVERSION=	1.9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Parsing log files from test runs, and displays in an XML syntax

RUN_DEPENDS=	${SITE_PERL}/Chart/Graph/Gnuplot.pm:${PORTSDIR}/graphics/p5-Chart-Graph \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig

PERL_CONFIGURE=	yes

MAN1=		parse_iozone.1 parse_test.1

MAN3=		Test::Metadata.3 Test::Parser.3 Test::Parser::Dbench.3 \
		Test::Parser::Dbt2.3 Test::Parser::Dbt5.3 Test::Parser::Mpstat.3 \
		Test::Parser::Iostat.3 Test::Parser::KernelBuild.3 \
		Test::Parser::Oprofile.3 Test::Parser::PgOptions.3 \
		Test::Parser::Readprofile.3 Test::Parser::Sar.3 \
		Test::Parser::SysbenchCPU.3 Test::Parser::SysbenchFileIO.3 \
		Test::Parser::Sysctl.3 Test::Parser::Vmstat.3 \
		Test::Parser::cthon.3 Test::Parser::ffsb.3 \
		Test::Parser::iozone.3 Test::Parser::lhcs_regression.3 \
		Test::Parser::ltp.3 Test::Parser::newpynfs.3

.include <bsd.port.mk>
