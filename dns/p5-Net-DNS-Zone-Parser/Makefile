# Created by: Jimmy Bergman jimmy@sigint.se
# $FreeBSD$

PORTNAME=	Net-DNS-Zone-Parser
PORTVERSION=	0.02
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jimmy@sigint.se
COMMENT=	A Perl5 preprocessor for normalising a zone file

BUILD_DEPENDS=	p5-Net-DNS>=0.64:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0.15:${PORTSDIR}/dns/p5-Net-DNS-SEC
RUN_DEPENDS=	p5-Net-DNS>=0.64:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0.15:${PORTSDIR}/dns/p5-Net-DNS-SEC

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::DNS::Zone::Parser.3

NO_STAGE=	yes
.include <bsd.port.mk>
