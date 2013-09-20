# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	Nexmo-SMS
PORTVERSION=	0.06
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RENEEB
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Send SMS via http://www.nexmo.com/ API

BUILD_DEPENDS=	p5-HTTP-Message>=5.836:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON-PP>=2.26000:${PORTSDIR}/converters/p5-JSON-PP \
		p5-libwww>=5.835:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Pod>=1.22:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.08:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

MAN3=		Nexmo::SMS.3 \
		Nexmo::SMS::BinaryMessage.3 \
		Nexmo::SMS::GetBalance.3 \
		Nexmo::SMS::MockLWP.3 \
		Nexmo::SMS::Response.3 \
		Nexmo::SMS::Response::Message.3 \
		Nexmo::SMS::TextMessage.3 \
		Nexmo::SMS::WAPPushMessage.3

NO_STAGE=	yes
.include <bsd.port.mk>
