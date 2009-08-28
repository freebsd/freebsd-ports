# Ports collection makefile for:	p5-Finance-QuoteTW
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Finance-QuoteTW
PORTVERSION=	0.09
DISTVERSIONPREFIX=	v
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fetch quotes of mutual funds in Taiwan

RUN_DEPENDS=	p5-Data-TreeDumper>=0:${PORTSDIR}/devel/p5-Data-TreeDumper \
		p5-Encode>=2.26:${PORTSDIR}/converters/p5-Encode \
		p5-HTML-Encoding>=0.6:${PORTSDIR}/www/p5-HTML-Encoding \
		p5-HTML-TableExtract>=2.1:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-Spiffy>=0.3:${PORTSDIR}/devel/p5-Spiffy \
		p5-WWW-Mechanize>=1.34:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-version>=0.76:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::QuoteTW.3 \
		Finance::QuoteTW::Allianz.3 \
		Finance::QuoteTW::Blackrock.3 \
		Finance::QuoteTW::Capital.3 \
		Finance::QuoteTW::Franklin.3 \
		Finance::QuoteTW::Iit.3 \
		Finance::QuoteTW::Jpmrich.3 \
		Finance::QuoteTW::Paradigm.3 \
		Finance::QuoteTW::Schroders.3 \
		Finance::QuoteTW::Tisc.3

.include <bsd.port.mk>
