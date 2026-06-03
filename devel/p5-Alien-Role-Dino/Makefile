PORTNAME=	Alien-Role-Dino
DISTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Experimental support for dynamic share Alien install
WWW=		https://metacpan.org/release/Alien-Role-Dino

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

_BR_DEPENDS=	p5-Alien-Build>=0.99:devel/p5-Alien-Build \
		p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers \
		p5-FFI-CheckLib>0:devel/p5-FFI-CheckLib \
		p5-Path-Tiny>0:devel/p5-Path-Tiny \
		p5-Role-Tiny>=1.003001:devel/p5-Role-Tiny
BUILD_DEPENDS=	${_BR_DEPENDS}
RUN_DEPENDS=	${_BR_DEPENDS}
TEST_DEPENDS=	${_BR_DEPENDS}

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
