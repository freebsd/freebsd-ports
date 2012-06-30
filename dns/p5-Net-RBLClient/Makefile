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

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/RBLCLient-${PORTVERSION}

PERL_CONFIGURE=	yes

MAN1=		spamalyze.1
MAN3=		Net::RBLClient.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
