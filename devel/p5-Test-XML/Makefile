# New ports collection makefile for:	devel/p5-Test-XML
# Date created:				04 November 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-XML
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Compare XML in perl tests

BUILD_DEPENDS=	${SITE_PERL}/XML/SemanticDiff.pm:${PORTSDIR}/textproc/p5-XML-SemanticDiff \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::XML.3 \
	Test::XML::SAX.3 \
	Test::XML::Twig.3 \
	Test::XML::XPath.3

.include <bsd.port.mk>
