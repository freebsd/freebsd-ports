# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Filter-DNS-TCP
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	POE Filter to handle DNS over TCP connections

BUILD_DEPENDS=	p5-Net-DNS>=0.66:dns/p5-Net-DNS \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-POE>=1.311:devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
