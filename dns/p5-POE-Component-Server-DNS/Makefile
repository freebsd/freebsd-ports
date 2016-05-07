# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	POE-Component-Server-DNS
PORTVERSION=	0.32
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Non-blocking, concurrent DNS server component

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Net-DNS>=0.58:dns/p5-Net-DNS \
		p5-POE>=0.38:devel/p5-POE \
		p5-POE-Component-Client-DNS>=1.051:dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-Client-DNS-Recursive>=1.04:dns/p5-POE-Component-Client-DNS-Recursive \
		p5-POE-Component-Generic>=0.09.10:net/p5-POE-Component-Generic \
		p5-POE-Filter-DNS-TCP>=0.04:dns/p5-POE-Filter-DNS-TCP
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
