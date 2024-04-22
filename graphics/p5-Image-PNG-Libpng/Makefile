PORTNAME=	Image-PNG-Libpng
PORTVERSION=	0.58
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the C library "libpng"
WWW=		https://metacpan.org/release/Image-PNG-Libpng

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/*.pl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Image/PNG/Libpng/Libpng.so

.include <bsd.port.mk>
