# ex:ts=8
# New ports collection makefile for:	p5-Imager
# Date created:			Jul 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Imager
PORTVERSION=	0.39
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.eecs.umich.edu/~addi/perl/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	t1:${PORTSDIR}/devel/t1lib \
		tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		ungif:${PORTSDIR}/graphics/libungif \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_FREETYPE=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ENV=	IM_LIBPATH="${LOCALBASE}/lib"
USE_GMAKE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Imager.3 Imager::Color.3 Imager::Color::Float.3 Imager::Expr.3 \
	Imager::Expr::Assem.3 Imager::Fill.3 Imager::Font.3 \
	Imager::Font::FreeType2.3 Imager::Font::Truetype.3 \
	Imager::Font::Type1.3 Imager::Font::Win32.3 Imager::Fountain.3 \
	Imager::Matrix2d.3 Imager::Regops.3 Imager::Transform.3 \
	Imager::interface.3 Imager::regmach.3

.include <bsd.port.mk>
