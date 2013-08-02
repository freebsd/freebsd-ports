# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-DNS-ToolKit
PORTVERSION=	0.47
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tools for working with DNS packets

BUILD_DEPENDS=	p5-Net-DNS-Codes>=0.09:${PORTSDIR}/dns/p5-Net-DNS-Codes \
		p5-NetAddr-IP>=1.30:${PORTSDIR}/net-mgmt/p5-NetAddr-IP
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::DNS::ToolKit.3 \
		Net::DNS::ToolKit::Debug.3 \
		Net::DNS::ToolKit::Question.3 \
		Net::DNS::ToolKit::RR.3 \
		Net::DNS::ToolKit::RR::A.3 \
		Net::DNS::ToolKit::RR::AAAA.3 \
		Net::DNS::ToolKit::RR::AFSDB.3 \
		Net::DNS::ToolKit::RR::CNAME.3 \
		Net::DNS::ToolKit::RR::HINFO.3 \
		Net::DNS::ToolKit::RR::ISDN.3 \
		Net::DNS::ToolKit::RR::MB.3 \
		Net::DNS::ToolKit::RR::MD.3 \
		Net::DNS::ToolKit::RR::MF.3 \
		Net::DNS::ToolKit::RR::MG.3 \
		Net::DNS::ToolKit::RR::MINFO.3 \
		Net::DNS::ToolKit::RR::MR.3 \
		Net::DNS::ToolKit::RR::MX.3 \
		Net::DNS::ToolKit::RR::NS.3 \
		Net::DNS::ToolKit::RR::NULL.3 \
		Net::DNS::ToolKit::RR::PTR.3 \
		Net::DNS::ToolKit::RR::RP.3 \
		Net::DNS::ToolKit::RR::RT.3 \
		Net::DNS::ToolKit::RR::SOA.3 \
		Net::DNS::ToolKit::RR::SRV.3 \
		Net::DNS::ToolKit::RR::TXT.3 \
		Net::DNS::ToolKit::RR::TYPE.3 \
		Net::DNS::ToolKit::RR::Template.3 \
		Net::DNS::ToolKit::RR::X25.3 \
		Net::DNS::ToolKit::Utilities.3

.include <bsd.port.mk>
