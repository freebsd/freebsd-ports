# New ports collection makefile for:	p5-JQuery
# Date created:		2007-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	JQuery
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/P/PE/PETERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Interface to Jquery, a language based on Javascript

RUN_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CSS.pm:${PORTSDIR}/textproc/p5-CSS \
		${SITE_PERL}/HTML/Table.pm:${PORTSDIR}/www/p5-HTML-Table \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		JQuery.3 \
		JQuery::Accordion.3 \
		JQuery::CSS.3 \
		JQuery::ClickMenu.3 \
		JQuery::Demo.3 \
		JQuery::Form.3 \
		JQuery::Heartbeat.3 \
		JQuery::Splitter.3 \
		JQuery::TableSorter.3 \
		JQuery::Tabs.3 \
		JQuery::Taconite.3 \
		JQuery::Treeview.3

.include <bsd.port.mk>
