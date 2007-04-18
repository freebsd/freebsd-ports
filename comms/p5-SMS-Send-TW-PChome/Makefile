# New ports collection makefile for:	p5-SMS-Send-TW-PChome
# Date created:		2007-04-06
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-TW-PChome
PORTVERSION=	0.01
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SMS
PKGNAMEPREFIX=	 p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for sms.pchome.com.tw

RUN_DEPENDS=	${SITE_PERL}/SMS/Send.pm:${PORTSDIR}/comms/p5-SMS-Send \
		${SITE_PERL}/Net/SMS/PChome.pm:${PORTSDIR}/net/p5-Net-SMS-PChome
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SMS::Send::TW::PChome.3

.include <bsd.port.mk>
