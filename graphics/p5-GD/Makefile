# New ports collection makefile for:	p5-GD
# Date created:				March 11, 2003
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	GD
PORTVERSION=	2.35
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-
DISTNAME=	GD-${PORTVERSION}

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	A perl5 interface to Gd Graphics Library version2

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	-options "JPEG,FT,XPM,GIF,PNG" \
		-lib_gd_path ${LOCALBASE} -lib_ft_path ${X11BASE} \
		-lib_png_path ${LOCALBASE} -lib_zlib_path ${LOCALBASE}

MAN1=		bdf2gdfont.pl.1
MAN3=		GD.3 GD::Polyline.3 GD::Simple.3 \
		GD::Image.3 GD::Polygon.3

.include <bsd.port.mk>
