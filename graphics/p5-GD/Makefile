# New ports collection makefile for:	p5-GD
# Date created:				March 11, 2003
# Whom:					Philip M. Gollucci <philip@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	GD
PORTVERSION=	2.15
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-
DISTNAME=	GD-${PORTVERSION}

MAINTAINER=	philip@p6m7g8.com
COMMENT=	A perl5 interface to Gd Graphics Library version2

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	-options "JPEG,FT,XPM" -lib_gd_path ${LOCALBASE} -lib_ft_path ${X11BASE} -lib_png_path ${LOCALBASE} -lib_zlib_path ${LOCALBASE}

MAN3=		GD.3 GD::Polyline.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
