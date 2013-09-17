# $FreeBSD$

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

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Test::XPath.3

OPTIONS_DEFINE=	CSS PODT

CSS_DESC=	Include CSS selectors
PODT_DESC=	Include Pod package test dependencies

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCSS}
RUN_DEPENDS+=	p5-HTML-Selector-XPath>=0.06:${PORTSDIR}/www/p5-HTML-Selector-XPath
.endif

.if ${PORT_OPTIONS:MPODT}
TEST_DEPENDS+=	p5-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Test-Pod>=1.41:${PORTSDIR}/devel/p5-Test-Pod
.endif

.include <bsd.port.mk>
