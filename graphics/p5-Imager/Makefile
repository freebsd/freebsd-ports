# New ports collection makefile for:	p5-Imager
# Date created:			Jul 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Imager
PORTVERSION=	0.91
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

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	IM_CFLAGS="${CFLAGS}" \
		IM_INCPATH=${LOCALBASE}/include \
		IM_LIBPATH=${LOCALBASE}/lib

MAN3=		Imager.3 \
		Imager::API.3 \
		Imager::APIRef.3 \
		Imager::Color.3 \
		Imager::Color::Float.3 \
		Imager::Color::Table.3 \
		Imager::Cookbook.3 \
		Imager::CountColor.3 \
		Imager::Draw.3 \
		Imager::Engines.3 \
		Imager::Expr.3 \
		Imager::Expr::Assem.3 \
		Imager::ExtUtils.3 \
		Imager::File::GIF.3 \
		Imager::File::ICO.3 \
		Imager::File::JPEG.3 \
		Imager::File::PNG.3 \
		Imager::File::SGI.3 \
		Imager::File::TIFF.3 \
		Imager::Files.3 \
		Imager::Fill.3 \
		Imager::Filter::Flines.3 \
		Imager::Filter::Mandelbrot.3 \
		Imager::Filters.3 \
		Imager::Font.3 \
		Imager::Font::BBox.3 \
		Imager::Font::FT2.3 \
		Imager::Font::FreeType2.3 \
		Imager::Font::T1.3 \
		Imager::Font::Truetype.3 \
		Imager::Font::Type1.3 \
		Imager::Font::Wrap.3 \
		Imager::Fountain.3 \
		Imager::Handy.3 \
		Imager::IO.3 \
		Imager::ImageTypes.3 \
		Imager::Inline.3 \
		Imager::LargeSamples.3 \
		Imager::Matrix2d.3 \
		Imager::Preprocess.3 \
		Imager::Probe.3 \
		Imager::Regops.3 \
		Imager::Security.3 \
		Imager::Test.3 \
		Imager::Transform.3 \
		Imager::Transformations.3 \
		Imager::Tutorial.3 \
		Imager::interface.3 \
		Imager::regmach.3

.include <bsd.port.mk>
