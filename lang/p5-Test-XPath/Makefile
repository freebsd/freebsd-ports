# New ports collection makefile for:	p5-Test-XPath
# Date created:		25 April 2010
# Whom:		milki
#
# $FreeBSD$
#

PORTNAME=	Test-XPath
PORTVERSION=	0.16
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Test XML and HTML content and structure with XPath expressions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-XML-LibXML>=1.70:${PORTSDIR}/textproc/p5-XML-LibXML

TEST_DEPENDS=	p5-Test-XPath>=0:${PORTSDIR}/lang/p5-Test-XPath

PERL_MODBUILD=	yes

MAN3=		Test::XPath.3

OPTIONS=	CSS "Include CSS selectors" Off \
		PODT "Include Pod package test dependencies" Off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_CSS)
RUN_DEPENDS+=	p5-HTML-Selector-XPath>=0.06:${PORTSDIR}/www/p5-HTML-Selector-XPath
.endif

.if !defined(WITHOUT_PODT)
TEST_DEPENDS+=	p5-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Test-Pod>=1.41:${PORTSDIR}/devel/p5-Test-Pod
.endif

.include <bsd.port.mk>
