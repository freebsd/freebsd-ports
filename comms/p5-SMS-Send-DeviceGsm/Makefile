# New ports collection makefile for:	p5-SMS-Send-DeviceGsm
# Date created:		2007-09-22
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-DeviceGsm
PORTVERSION=	1.06
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	An SMS::Send driver for Device::Gsm

BUILD_DEPENDS=	p5-SMS-Send>=0.04:${PORTSDIR}/comms/p5-SMS-Send \
		p5-Device-Gsm>=1.45:${PORTSDIR}/comms/p5-Device-Gsm
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.1+

MAN3=		SMS::Send::DeviceGsm.3

.include <bsd.port.mk>
