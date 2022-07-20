PORTNAME=	Astro-Hipparcos
PORTVERSION=	0.09
PORTREVISION=	3
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for reading the Hipparcos star catalog

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-XSpp>=0.06:devel/p5-ExtUtils-XSpp

MAKE_ARGS=	CC="${CXX}"
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Astro/Hipparcos/Hipparcos.so

.include <bsd.port.mk>
