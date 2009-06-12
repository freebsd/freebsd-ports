# New ports collection makefile for:	p5-GD
# Date created:				March 11, 2003
# Whom:					Philip M. Gollucci <pgollucci@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GD
PORTVERSION=	2.43
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	GD-${PORTVERSION}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A perl5 interface to Gd Graphics Library version2

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	-options "JPEG,FT,XPM,GIF,PNG" \
		-lib_gd_path ${LOCALBASE} -lib_ft_path} \
		-lib_png_path ${LOCALBASE} -lib_zlib_path

MAN1=		bdf2gdfont.pl.1
MAN3=		GD.3 GD::Polyline.3 GD::Simple.3 \
		GD::Image.3 GD::Polygon.3

.include <bsd.port.mk>
