# New ports collection makefile for:	p5-Net-Nslookup
# Date created:				14 October 2003
# Whom:	      				clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Net-Nslookup
PORTVERSION=	1.16
CATEGORIES=	dns perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Provides the capabilities of the standard tool nslookup(1)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Net::Nslookup.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
