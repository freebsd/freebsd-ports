# New ports collection makefile for:	p5-SMS-Send-DeviceGsm
# Date created:		2007-09-22
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-DeviceGsm
PORTVERSION=	0.02
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	An SMS::Send driver for Device::Gsm

RUN_DEPENDS=	${SITE_PERL}/SMS/Send.pm:${PORTSDIR}/comms/p5-SMS-Send \
		${SITE_PERL}/Device/Gsm.pm:${PORTSDIR}/comms/p5-Device-Gsm
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SMS::Send::DeviceGsm.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.0 due to dependency. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
