# Created by: Andrew Greenwood <greenwood.andy@gmail.com>
# $FreeBSD$

PORTNAME=	Net-DNSBL-MultiDaemon
PORTVERSION=	0.39
PORTREVISION=	1
CATEGORIES=	dns mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Net::DNSBL::MultiDaemon - multi DNSBL prioritization

LICENSE=	ART10 GPLv1 GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-SafeDO>=0.12:devel/p5-File-SafeDO \
		p5-Geo-IP-PurePerl>=1.10:net/p5-Geo-IP-PurePerl \
		p5-Net-DNS-Codes>=0.09:dns/p5-Net-DNS-Codes \
		p5-Net-DNS-ToolKit>=0.47:dns/p5-Net-DNS-ToolKit \
		p5-Net-NBsocket>=0.23:net/p5-Net-NBsocket \
		p5-NetAddr-IP>=4.067:net-mgmt/p5-NetAddr-IP \
		p5-Unix-Syslog>=0.97:sysutils/p5-Unix-Syslog
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	RHBL
OPTIONS_DEFAULT=RHBL
RHBL_DESC=	RHBL checking of URBL domains
RHBL_BUILD_DEPENDS=	p5-URBL-Prepare>=0.08:dns/p5-URBL-Prepare
RHBL_RUN_DEPENDS=	p5-URBL-Prepare>=0.08:dns/p5-URBL-Prepare

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	MultiDaemon.pm lib/Net/DNSBL/Utilities.pm

.include <bsd.port.mk>
