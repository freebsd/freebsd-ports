# New ports collection makefile for:	p5-Net-Nslookup
# Date created:				14 October 2003
# Whom:	      				clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Net-Nslookup
PORTVERSION=	1.15
CATEGORIES=	dns perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Provides the capabilities of the standard tool nslookup(1)

BUILD_DEPENDS=	${SITE_PERL}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Net::Nslookup.3

.include <bsd.port.mk>
