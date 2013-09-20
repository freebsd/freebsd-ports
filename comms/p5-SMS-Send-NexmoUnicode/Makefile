# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-NexmoUnicode
PORTVERSION=	0.01
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JNLIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	SMS::Send driver for www.nexmo.com (Unicode)

BUILD_DEPENDS=	p5-Nexmo-SMS>=0.04:${PORTSDIR}/comms/p5-Nexmo-SMS \
		p5-SMS-Send>=0:${PORTSDIR}/comms/p5-SMS-Send
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		SMS::Send::NexmoUnicode.3

NO_STAGE=	yes
.include <bsd.port.mk>
