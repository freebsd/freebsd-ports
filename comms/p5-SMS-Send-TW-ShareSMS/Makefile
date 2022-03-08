# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>

PORTNAME=	SMS-Send-TW-ShareSMS
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for www.ShareSMS.com

BROKEN=		Service is no longer available
DEPRECATED=	Service provider is no longer around
EXPIRATION_DATE=2022-03-31

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-SMS-Send>=0.03:comms/p5-SMS-Send \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=2:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
