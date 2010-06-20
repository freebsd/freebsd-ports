# New ports collection makefile for:	p5-Test-XPath
# Date created:		25 April 2010
# Whom:		milki
#
# $FreeBSD$
#

PORTNAME=	Test-XPath
PORTVERSION=	0.13
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	 ../../authors/id/D/DW/DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Test XML and HTML content and structure with XPath expressions

BUILD_DEPENDS=	p5-Test-Simple>=0.70:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Module-Build>=0.30:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS=	p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML

PERL_MODBUILD=	YES

MAN3=	Test::XPath.3

.include <bsd.port.mk>
