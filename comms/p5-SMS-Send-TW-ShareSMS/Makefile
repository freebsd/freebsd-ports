# New ports collection makefile for:	p5-SMS-Send-TW-ShareSMS
# Date created:		2007-10-06
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-TW-ShareSMS
PORTVERSION=	0.01
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	SMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for www.ShareSMS.com

RUN_DEPENDS=	${SITE_PERL}/SMS/Send.pm:${PORTSDIR}/comms/p5-SMS-Send \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${SITE_PERL}/SMS/Send.pm:${PORTSDIR}/comms/p5-SMS-Send \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		SMS::Send::TW::ShareSMS.3

.include <bsd.port.mk>
