# New ports collection makefile for:	p5-Imager
# Date created:			Jul 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Imager
PORTVERSION=	0.85
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TONYC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl module for manipulating gray, color and rgba format images

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		t1:${PORTSDIR}/devel/t1lib \
		tiff:${PORTSDIR}/graphics/tiff \
		gif.5:${PORTSDIR}/graphics/giflib

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	IM_LIBPATH="${LOCALBASE}/lib" \
		IM_CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

.include "Makefile.man"

.include <bsd.port.mk>
