# New ports collection makefile for:	p5-Net-Nslookup
# Date created:				14 October 2003
# Whom:	      				clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Net-Nslookup
PORTVERSION=	2.01
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Provides the capabilities of the standard tool nslookup(1)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Net::Nslookup.3

.include <bsd.port.mk>
