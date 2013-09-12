# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-ShareSMS
PORTVERSION=	0.02
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for www.ShareSMS.com

BUILD_DEPENDS=	p5-SMS-Send>=0.03:${PORTSDIR}/comms/p5-SMS-Send \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=2:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		SMS::Send::TW::ShareSMS.3

.include <bsd.port.mk>
