# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Finance-YahooQuote
PORTVERSION=	0.25
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get stock quotes from Yahoo! Finance

RUN_DEPENDS=	p5-HTML-Parser>=2.2:www/p5-HTML-Parser \
		p5-libwww>=1.62:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
