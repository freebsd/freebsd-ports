# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	Cisco-UCS
PORTVERSION=	0.30
PORTEPOCH=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Perl interface to the Cisco UCS XML API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Cisco::UCS.3 Cisco::UCS::Blade.3 Cisco::UCS::Chassis.3 \
		Cisco::UCS::Common::EthernetPort.3 Cisco::UCS::Common::Fan.3 \
		Cisco::UCS::Common::FanModule.3 Cisco::UCS::Common::PSU.3 \
		Cisco::UCS::Common::SwitchCard.3 Cisco::UCS::FEX.3 \
		Cisco::UCS::Fault.3 Cisco::UCS::Interconnect.3 \
		Cisco::UCS::MgmtEntity.3 Cisco::UCS::ServiceProfile.3

.include <bsd.port.mk>
