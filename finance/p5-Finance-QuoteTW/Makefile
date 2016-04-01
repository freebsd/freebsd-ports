# Created by: chinsan
# $FreeBSD$

PORTNAME=	Finance-QuoteTW
PORTVERSION=	0.09
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fetch quotes of mutual funds in Taiwan

RUN_DEPENDS=	p5-Data-TreeDumper>=0:devel/p5-Data-TreeDumper \
		p5-HTML-Encoding>=0.6:www/p5-HTML-Encoding \
		p5-HTML-TableExtract>=2.1:www/p5-HTML-TableExtract \
		p5-Spiffy>=0.3:devel/p5-Spiffy \
		p5-WWW-Mechanize>=1.34:www/p5-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
