# New ports collection makefile for: 	gphoto
# Version required:	gphoto-19990511
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $Id$
#

DISTNAME=	gphoto-19990511
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gphoto.org/projects/gphoto/pub/snap/ \
		http://www.freenix.no/~anders/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.4:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes

MAN1=		gphoto.1

ALL_TARGET=

.include <bsd.port.mk>
