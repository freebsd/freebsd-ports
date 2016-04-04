# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DNS-ZoneFile-Fast
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse BIND8/9 zone files

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	p5-Net-DNS>=0.65:dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0.15:dns/p5-Net-DNS-SEC
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
