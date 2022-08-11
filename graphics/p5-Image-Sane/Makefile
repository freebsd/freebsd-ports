PORTNAME=	Image-Sane
PORTVERSION=	5
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl extension for the SANE (Scanner Access Now Easy) Project

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		sane-backends>=1.0.19:graphics/sane-backends \
		${RUN_DEPENDS}
LIB_DEPENDS=	libsane.so:graphics/sane-backends
RUN_DEPENDS=	p5-Exception-Class>=1.43:devel/p5-Exception-Class \
		p5-Readonly>=0:devel/p5-Readonly
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Try-Tiny>=0.28:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Image/Sane/Sane.so

.include <bsd.port.mk>
