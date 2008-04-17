# New ports collection makefile for:	p5-Net-RBLClient
# Date created:		2006-07-13
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-RBLClient
PORTVERSION=	0.5
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Queries multiple Realtime Blackhole Lists in parallel

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS/Packet.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/RBLCLient-${PORTVERSION}

PERL_CONFIGURE=	yes

MAN1=		spamalyze.1
MAN3=		Net::RBLClient.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
