# Ports collection makefile for:	p5-Finance-QuoteTW
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Finance-QuoteTW
PORTVERSION=	0.08
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Fetch quotes of mutual funds in Taiwan

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::QuoteTW.3 \
		Finance::QuoteTW::Allianz.3 \
		Finance::QuoteTW::Blackrock.3 \
		Finance::QuoteTW::Capital.3 \
		Finance::QuoteTW::Cathay.3 \
		Finance::QuoteTW::Franklin.3 \
		Finance::QuoteTW::Iit.3 \
		Finance::QuoteTW::Jpmrich.3 \
		Finance::QuoteTW::Paradigm.3 \
		Finance::QuoteTW::Schroders.3 \
		Finance::QuoteTW::Tisc.3

.include <bsd.port.mk>
