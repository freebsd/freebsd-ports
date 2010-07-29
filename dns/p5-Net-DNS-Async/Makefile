# New ports collection makefile for:	p5-Net-DNS-Async
# Date created:				3 May 2008
# Whom:				 	Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	Net-DNS-Async
PORTVERSION=	1.07
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Asynchronous DNS helper for high volume applications

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::DNS::Async.3

.include <bsd.port.mk>
