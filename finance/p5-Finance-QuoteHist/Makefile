# New ports collection makefile for:	Finance::QuoteHist
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Finance-QuoteHist
PORTVERSION=	1.12
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fetching historical stock quotes

RUN_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-HTML-TableExtract>=2.07:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Regexp-Common>0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Finance::QuoteHist.3 \
		Finance::QuoteHist::Generic.3 \
		Finance::QuoteHist::MSN.3 \
		Finance::QuoteHist::QuoteMedia.3 \
		Finance::QuoteHist::Yahoo.3 \
		Finance::QuoteHist::Yahoo::Australia.3 \
		Finance::QuoteHist::Google.3 \
		Finance::QuoteHist::BusinessWeek.3 \

.include <bsd.port.mk>
