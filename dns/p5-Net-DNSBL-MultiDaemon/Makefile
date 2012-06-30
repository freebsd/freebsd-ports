# New ports collection makefile for:    mail/p5-Net-DNSBL-MultiDaemon
# Date created:                         17 August 2007
# Whom:                                 Andrew Greenwood <greenwood.andy@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-DNSBL-MultiDaemon
PORTVERSION=	0.29
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	greenwood.andy@gmail.com
COMMENT=	Net::DNSBL::MultiDaemon - multi DNSBL prioritization

BUILD_DEPENDS=	p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		p5-Geo-IP-PurePerl>=0:${PORTSDIR}/net/p5-Geo-IP-PurePerl \
		p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-Net-DNS-Codes>=0:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0:${PORTSDIR}/dns/p5-Net-DNS-ToolKit
RUN_DEPENDS:=	${BUILD_DEPENDS} \
				p5-File-SafeDO>=0:${PORTSDIR}/devel/p5-File-SafeDO

PERL_CONFIGURE=	yes

MAN3=		Net::DNSBL::MultiDaemon.3 Net::DNSBL::Utilities.3

.include <bsd.port.mk>
