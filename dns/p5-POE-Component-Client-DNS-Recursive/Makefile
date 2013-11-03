# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Client-DNS-Recursive
PORTVERSION=	1.06
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Recursive DNS client for POE

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-IP-Minimal>=0:${PORTSDIR}/net/p5-Net-IP-Minimal \
		p5-POE>=1.004:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
