# ex:ts=8
# New ports collection makefile for:	p5-Imager
# Date created:			Jul 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Imager
PORTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.eecs.umich.edu/~addi/perl/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A Perl module for manipulating gray, color and rgba format images

LIB_DEPENDS=	t1:${PORTSDIR}/devel/t1lib \
		tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		ungif:${PORTSDIR}/graphics/libungif \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_FREETYPE=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ENV=	IM_LIBPATH="${LOCALBASE}/lib" \
		IM_INCPATH="${LOCALBASE}/include/freetype1/freetype"
USE_GMAKE=	yes

MAN3=	Imager.3 Imager::Color.3 Imager::Color::Float.3 Imager::Expr.3 \
	Imager::Expr::Assem.3 Imager::Fill.3 Imager::Font.3 \
	Imager::Font::FreeType2.3 Imager::Font::Truetype.3 \
	Imager::Font::Type1.3 Imager::Font::Win32.3 Imager::Fountain.3 \
	Imager::Matrix2d.3 Imager::Regops.3 Imager::Transform.3 \
	Imager::interface.3 Imager::regmach.3 Imager::Engines.3 \
	Imager::Transformations.3 Imager::Draw.3 Imager::Files.3 \
	Imager::ImageTypes.3 Imager::Filters.3

.include <bsd.port.mk>
