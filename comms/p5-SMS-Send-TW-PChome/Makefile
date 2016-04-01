# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-PChome
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	 p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for sms.pchome.com.tw

RUN_DEPENDS=	p5-SMS-Send>=0:comms/p5-SMS-Send \
		p5-Text-Iconv>=0:converters/p5-Text-Iconv \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
