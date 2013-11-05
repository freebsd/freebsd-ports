# Created by: ijliao
# $FreeBSD$

PORTNAME=	Imager
PORTVERSION=	0.97
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for manipulating gray, color, and rgba format images

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:${PORTSDIR}/devel/p5-Devel-CheckLib
LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		gif:${PORTSDIR}/graphics/giflib \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		t1:${PORTSDIR}/devel/t1lib \
		tiff:${PORTSDIR}/graphics/tiff
TEST_DEPENDS=	p5-CPAN-Meta>=0:${PORTSDIR}/devel/p5-CPAN-Meta \
		p5-Inline>=0:${PORTSDIR}/devel/p5-Inline

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	IM_CFLAGS="${CFLAGS}" \
		IM_INCPATH=${LOCALBASE}/include \
		IM_LIBPATH=${LOCALBASE}/lib

.include <bsd.port.mk>
