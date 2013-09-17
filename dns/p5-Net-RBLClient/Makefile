# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

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

USES=		perl5
USE_PERL5=	configure

MAN1=		spamalyze.1
MAN3=		Net::RBLClient.3

.include <bsd.port.mk>
