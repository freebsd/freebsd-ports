# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Finance-QuoteHist
PORTVERSION=	1.28
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fetching historical stock quotes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-HTML-TableExtract>=2.07:www/p5-HTML-TableExtract \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
