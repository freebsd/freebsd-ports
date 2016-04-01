# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Client-DNS-Recursive
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Recursive DNS client for POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-IP-Minimal>=0:net/p5-Net-IP-Minimal \
		p5-POE>=1.004:devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
