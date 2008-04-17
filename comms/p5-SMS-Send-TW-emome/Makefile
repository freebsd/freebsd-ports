# New ports collection makefile for:	p5-SMS-Send-TW-emome
# Date created:		2007-10-10
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-TW-emome
PORTVERSION=	0.01
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for www.emome.net

RUN_DEPENDS=	${SITE_PERL}/SMS/Send.pm:${PORTSDIR}/comms/p5-SMS-Send \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv
BUILD_DEPENDS=	${SITE_PERL}/SMS/Send.pm:${PORTSDIR}/comms/p5-SMS-Send \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv	

PERL_CONFIGURE=	yes

MAN3=		SMS::Send::TW::emome.3

.include <bsd.port.mk>
