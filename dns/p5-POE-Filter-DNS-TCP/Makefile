# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Filter-DNS-TCP
PORTVERSION=	0.04
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A POE Filter to handle DNS over TCP connections

BUILD_DEPENDS=	p5-Net-DNS>=0.66:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-POE>=1.311:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	POE::Filter::DNS::TCP.3

.include <bsd.port.mk>
