# ex:ts=8
# Ports collection makefile for:	Finance::TW::TSEQuote
# Date created:			Apr 28, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Finance-TW-TSEQuote
PORTVERSION=	0.2
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Check stock quotes from Taiwan Security Exchange

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::TW::TSEQuote.3

.include <bsd.port.mk>
