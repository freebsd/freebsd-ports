# New ports collection makefile for:	Finance::QuoteHist
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Finance-QuoteHist
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Perl module for fetching historical stock quotes

BUILD_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		${SITE_PERL}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::QuoteHist.3 \
		Finance::QuoteHist::QuoteMedia.3 \
		Finance::QuoteHist::Generic.3 \
		Finance::QuoteHist::Yahoo.3

.include <bsd.port.mk>
