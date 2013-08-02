# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Finance-QuoteHist
PORTVERSION=	1.19
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fetching historical stock quotes

BUILD_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-HTML-TableExtract>=2.07:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-HTML-TableExtract>=2.07:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=		Finance::QuoteHist.3 \
		Finance::QuoteHist::BusinessWeek.3 \
		Finance::QuoteHist::Generic.3 \
		Finance::QuoteHist::Google.3 \
		Finance::QuoteHist::Investopedia.3 \
		Finance::QuoteHist::MSN.3 \
		Finance::QuoteHist::QuoteMedia.3 \
		Finance::QuoteHist::StockNod.3 \
		Finance::QuoteHist::Yahoo.3 \
		Finance::QuoteHist::Yahoo::Australia.3

.include <bsd.port.mk>
