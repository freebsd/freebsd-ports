# New ports collection makefile for:	pgeodns
# Date created:		16 May 2009
# Whom:				Phillip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	pgeodns
PORTVERSION=	1.41
CATEGORIES=	dns perl5
MASTER_SITES=	http://cloud.github.com/downloads/abh/pgeodns/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Geographic NameServer

BUILD_DEPENDS=	p5-Geo-IP>=0:${PORTSDIR}/net/p5-Geo-IP \
  				p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
				p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

NO_MANCOMPRESS=	no
MAN1=	pgeodns.1

.include <bsd.port.mk>
