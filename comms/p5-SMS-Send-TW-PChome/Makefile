# New ports collection makefile for:	p5-SMS-Send-TW-PChome
# Date created:		2007-04-06
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-TW-PChome
PORTVERSION=	0.03
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	 p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for sms.pchome.com.tw

RUN_DEPENDS=	${SITE_PERL}/SMS/Send.pm:${PORTSDIR}/comms/p5-SMS-Send \
  		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SMS::Send::TW::PChome.3

.include <bsd.port.mk>
