# New ports collection makefile for:	libgrass5
# Date created: 		26 December 2000
# Whom:			J. Pennington <john@coastalgeology.org>
#
# $FreeBSD$
#

PORTNAME=	libgrass5
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://gdal.velocet.ca/projects/grass/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of functions from the GRASS GIS application for use by non-GRASS programs

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
