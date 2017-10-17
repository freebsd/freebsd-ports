# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Image-Compare
PORTVERSION=	1.03
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compare two images in a variety of ways

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Imager>=0:graphics/p5-Imager \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-CheckManifest>=0:devel/p5-Test-CheckManifest \
		p5-Test-Pod>=1.26:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.08:devel/p5-Test-Pod-Coverage

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
