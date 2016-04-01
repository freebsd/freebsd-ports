# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Client-DNSBL
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl POE component that provides non-blocking DNSBL lookups

BUILD_DEPENDS=	p5-POE>=1.004:devel/p5-POE \
		p5-Net-IP-Minimal>=0:net/p5-Net-IP-Minimal \
		p5-POE-Component-Client-DNS>=0:dns/p5-POE-Component-Client-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
