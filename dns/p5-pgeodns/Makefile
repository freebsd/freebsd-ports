# New ports collection makefile for:	pgeodns
# Date created:		16 May 2009
# Whom:				Phillip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	pgeodns
PORTVERSION=	1.32
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Geographic NameServer

BUILD_DEPENDS=	p5-Geo-IP>=0:${PORTSDIR}/net/p5-Geo-IP \
  				p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
				p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	pgeodns.pl.1

.include <bsd.port.mk>
