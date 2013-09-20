# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Finance-YahooQuote
PORTVERSION=	0.24
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Get stock quotes from Yahoo! Finance

RUN_DEPENDS=	p5-HTML-Parser>=2.2:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=1.62:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		yahooquote.1
MAN3=		Finance::YahooQuote.3

NO_STAGE=	yes
.include <bsd.port.mk>
