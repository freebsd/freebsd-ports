# New ports collection makefile for:	fpx
# Date created:				Jan 10 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libfpx
PORTVERSION=	1.2.0.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.graphicsmagick.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	GraphicsMagick/delegates

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library routines for working with Flashpix images

PATCHFILES=	libfpx.diff
PATCH_SITES=	http://www.kdewebdev.org/~amantia/
PATCH_DIST_STRIP=-p1
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg
MAKE_ARGS+=	-j2
USE_BZIP2=	yes

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd

.include <bsd.port.mk>
