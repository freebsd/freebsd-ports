# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	Net-DNS-Async
PORTVERSION=	1.07
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Asynchronous DNS helper for high volume applications

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::DNS::Async.3

NO_STAGE=	yes
.include <bsd.port.mk>
