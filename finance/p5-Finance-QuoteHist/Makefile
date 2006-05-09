# New ports collection makefile for:	Finance::QuoteHist
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Finance-QuoteHist
PORTVERSION=	1.08
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fetching historical stock quotes

RUN_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-HTML-TableExtract>=2.07:${PORTSDIR}/www/p5-HTML-TableExtract
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=		Finance::QuoteHist.3 \
		Finance::QuoteHist::Generic.3 \
		Finance::QuoteHist::MSN.3 \
		Finance::QuoteHist::QuoteMedia.3 \
		Finance::QuoteHist::Yahoo.3

.include <bsd.port.mk>
