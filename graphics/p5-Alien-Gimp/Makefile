# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Alien-Gimp
PORTVERSION=	0.07
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Encapsulate install info for GIMP

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.402:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-IO-All>=0:devel/p5-IO-All
LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app
TEST_DEPENDS=	p5-Inline-C>=0.67:devel/p5-Inline-C \
		p5-Inline>=0.78:devel/p5-Inline

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
