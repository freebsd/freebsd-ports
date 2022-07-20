PORTNAME=	DateTime-Astro
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Functions For Astromical Calendars

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build-XSUtil>=0.16:devel/p5-Module-Build-XSUtil \
		${RUN_DEPENDS}
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Set>=0:devel/p5-DateTime-Set
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		localbase perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DateTime/Astro/Astro.so

.include <bsd.port.mk>
