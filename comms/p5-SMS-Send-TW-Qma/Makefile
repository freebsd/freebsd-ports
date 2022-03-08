# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>

PORTNAME=	SMS-Send-TW-Qma
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for http://www.qma.com/

BROKEN=		Service is no longer available
DEPRECATED=	QMA service provider is no longer around
EXPIRATION_DATE=2022-03-31

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-SMS-Send>=0:comms/p5-SMS-Send \
		p5-Crypt-SSLeay>=0.57:security/p5-Crypt-SSLeay \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
