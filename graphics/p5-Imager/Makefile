# ex:ts=8
# New ports collection makefile for:	p5-Imager
# Date created:			Jul 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Imager
PORTVERSION=	0.65
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A Perl module for manipulating gray, color and rgba format images

LIB_DEPENDS=	\
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		t1:${PORTSDIR}/devel/t1lib \
		tiff:${PORTSDIR}/graphics/tiff \
		ungif:${PORTSDIR}/graphics/libungif

USE_FREETYPE2=	yes
PERL_CONFIGURE=	5.8.0+
CONFIGURE_ENV=	IM_LIBPATH="${LOCALBASE}/lib" \
		IM_CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		IM_INCPATH="${LOCALBASE}/include/freetype2/freetype"

.include "Makefile.man"

.include <bsd.port.mk>
