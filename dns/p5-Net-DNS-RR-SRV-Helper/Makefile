# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Net-DNS-RR-SRV-Helper
PORTVERSION=	0.0.0
PORTREVISION=	2
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Orders SRV records by priority and weight for Net::DNS

BUILD_DEPENDS=	p5-Net-DNS>=0.68:dns/p5-Net-DNS \
		p5-Sort-Naturally>=1.03:textproc/p5-Sort-Naturally
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
