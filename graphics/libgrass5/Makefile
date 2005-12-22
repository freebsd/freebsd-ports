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
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of functions from the GRASS GIS application for use by non-GRASS programs

DEPRECATED=	mastersite disappeared, no longer maintained by author
EXPIRATION_DATE=	2006-02-22

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
