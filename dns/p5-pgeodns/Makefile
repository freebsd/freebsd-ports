# $FreeBSD$

PORTNAME=	pgeodns
PORTVERSION=	1.41
PORTREVISION=	2
CATEGORIES=	dns perl5
MASTER_SITES=	GHC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Geographic NameServer

BUILD_DEPENDS=	p5-Geo-IP>=0:net/p5-Geo-IP \
		p5-JSON>=0:converters/p5-JSON \
		p5-Net-DNS>=0:dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure
USE_GITHUB=	yes
GH_ACCOUNT=	abh

.include <bsd.port.mk>
