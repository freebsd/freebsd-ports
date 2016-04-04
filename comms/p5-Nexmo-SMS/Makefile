# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	Nexmo-SMS
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RENEEB
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	Send SMS via http://www.nexmo.com/ API

BUILD_DEPENDS=	p5-HTTP-Message>=5.836:www/p5-HTTP-Message \
		p5-JSON-PP>=2.26000:converters/p5-JSON-PP \
		p5-libwww>=5.835:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Pod>=1.22:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.08:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
