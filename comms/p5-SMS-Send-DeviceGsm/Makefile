# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-DeviceGsm
PORTVERSION=	1.06
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	An SMS::Send driver for Device::Gsm

BUILD_DEPENDS=	p5-SMS-Send>=0.04:${PORTSDIR}/comms/p5-SMS-Send \
		p5-Device-Gsm>=1.45:${PORTSDIR}/comms/p5-Device-Gsm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
