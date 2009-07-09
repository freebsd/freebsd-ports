# New ports collection makefile for:    mail/p5-Net-DNSBL-MultiDaemon
# Date created:                         17 August 2007
# Whom:                                 Andrew Greenwood <greenwood.andy@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-DNSBL-MultiDaemon
PORTVERSION=	0.26
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	greenwood.andy@gmail.com
COMMENT=	Net::DNSBL::MultiDaemon - multi DNSBL prioritization

BUILD_DEPENDS=	${SITE_PERL}/mach/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/Geo/IP/PurePerl.pm:${PORTSDIR}/net/p5-Geo-IP-PurePerl \
		${SITE_PERL}/mach/NetAddr/IP.pm:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		${SITE_PERL}/Net/DNS/Codes.pm:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		${SITE_PERL}/mach/Net/DNS/ToolKit.pm:${PORTSDIR}/dns/p5-Net-DNS-ToolKit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::DNSBL::MultiDaemon.3 Net::DNSBL::Utilities.3

.include <bsd.port.mk>
