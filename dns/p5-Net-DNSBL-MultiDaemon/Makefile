# Created by: Andrew Greenwood <greenwood.andy@gmail.com>
# $FreeBSD$

PORTNAME=	Net-DNSBL-MultiDaemon
PORTVERSION=	0.37
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Net::DNSBL::MultiDaemon - multi DNSBL prioritization

LICENSE=	ART10 GPLv1 GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-SafeDO>=0.12:${PORTSDIR}/devel/p5-File-SafeDO \
		p5-Geo-IP-PurePerl>=1.10:${PORTSDIR}/net/p5-Geo-IP-PurePerl \
		p5-Net-DNS-Codes>=0.09:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0.47:${PORTSDIR}/dns/p5-Net-DNS-ToolKit \
		p5-Net-NBsocket>=0.23:${PORTSDIR}/net/p5-Net-NBsocket \
		p5-NetAddr-IP>=4.067:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-Unix-Syslog>=0.97:${PORTSDIR}/sysutils/p5-Unix-Syslog
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	MultiDaemon.pm lib/Net/DNSBL/Utilities.pm

.include <bsd.port.mk>
