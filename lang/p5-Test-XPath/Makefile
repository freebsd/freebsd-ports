PORTNAME=	Test-XPath
PORTVERSION=	0.19
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test XML and HTML content and structure with XPath expressions
WWW=		https://metacpan.org/release/Test-XPath

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-XML-LibXML>=1.70:textproc/p5-XML-LibXML

USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	CSS

CSS_DESC=	Include CSS selectors
CSS_RUN_DEPENDS=p5-HTML-Selector-XPath>=0.06:www/p5-HTML-Selector-XPath

.include <bsd.port.mk>
