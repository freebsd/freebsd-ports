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
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
