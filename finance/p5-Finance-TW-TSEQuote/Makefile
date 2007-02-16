# ex:ts=8
# Ports collection makefile for:	Finance::TW::TSEQuote
# Date created:			Apr 28, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Finance-TW-TSEQuote
PORTVERSION=	0.2.6
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Check stock quotes from Taiwan Security Exchange

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS} \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Finance-TW-EmergingQuote>=0:${PORTSDIR}/finance/p5-Finance-TW-EmergingQuote

PERL_CONFIGURE=	yes

MAN1=		pfq.1
MAN3=		Finance::TW::TSEQuote.3

.include <bsd.port.mk>
