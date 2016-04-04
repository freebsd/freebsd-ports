# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-DNSBL-Statistics
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Gather DNSBL Statistics

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-DNS-Codes>=0.09:dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0.41:dns/p5-Net-DNS-ToolKit \
		p5-Net-DNSBL-MultiDaemon>=0.26:dns/p5-Net-DNSBL-MultiDaemon
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
