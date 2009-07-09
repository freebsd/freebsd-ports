# New ports collection makefile for:	p5-Net-DNSBL-Statistics
# Date created:		2008-01-07
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-DNSBL-Statistics
PORTVERSION=	0.06
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Gather DNSBL Statistics

RUN_DEPENDS=	p5-Net-DNS-Codes>=0.09:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0.35:${PORTSDIR}/dns/p5-Net-DNS-ToolKit \
		p5-Net-DNSBL-MultiDaemon>=0.22:${PORTSDIR}/dns/p5-Net-DNSBL-MultiDaemon
BUILD_DEPENDS=	p5-Net-DNS-Codes>=0.09:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0.35:${PORTSDIR}/dns/p5-Net-DNS-ToolKit \
		p5-Net-DNSBL-MultiDaemon>=0.22:${PORTSDIR}/dns/p5-Net-DNSBL-MultiDaemon

PERL_CONFIGURE=	yes

MAN3=		Net::DNSBL::Statistics.3

.include <bsd.port.mk>
