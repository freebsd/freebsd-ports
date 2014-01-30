# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-Qma
PORTVERSION=	0.01
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for http://www.qma.com/

RUN_DEPENDS=	p5-SMS-Send>=0:${PORTSDIR}/comms/p5-SMS-Send \
		p5-Crypt-SSLeay>=0.57:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
