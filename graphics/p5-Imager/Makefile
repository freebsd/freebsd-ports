# Created by: ijliao
# $FreeBSD$

PORTNAME=	Imager
PORTVERSION=	1.006
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for manipulating gray, color, and rgba format images

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libt1.so:devel/t1lib \
		libtiff.so:graphics/tiff
TEST_DEPENDS=	p5-Inline>=0:devel/p5-Inline \
		p5-Inline-C>=0:devel/p5-Inline-C

USES=		jpeg perl5
USE_PERL5=	configure
CONFIGURE_ENV=	IM_CFLAGS="${CFLAGS}" \
		IM_INCPATH=${LOCALBASE}/include \
		IM_LIBPATH=${LOCALBASE}/lib

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Imager \
		-name "*.so" -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
