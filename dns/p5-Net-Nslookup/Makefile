# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	Net-Nslookup
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides the capabilities of the standard tool nslookup(1)

BUILD_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
