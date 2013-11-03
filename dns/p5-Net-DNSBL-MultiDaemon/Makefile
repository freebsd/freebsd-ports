# Created by: Andrew Greenwood <greenwood.andy@gmail.com>
# $FreeBSD$

PORTNAME=	Net-DNSBL-MultiDaemon
PORTVERSION=	0.29
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Net::DNSBL::MultiDaemon - multi DNSBL prioritization

BUILD_DEPENDS=	p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		p5-Geo-IP-PurePerl>=0:${PORTSDIR}/net/p5-Geo-IP-PurePerl \
		p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-Net-DNS-Codes>=0:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0:${PORTSDIR}/dns/p5-Net-DNS-ToolKit
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-File-SafeDO>=0:${PORTSDIR}/devel/p5-File-SafeDO

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
