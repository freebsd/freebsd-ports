# New ports collection makefile for:    gtksee
# Version required:     0.1.4
# Date created:         Sun Nov 22 12:08:18 CET 1998
# Whom:                 Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $Id$
#

DISTNAME=       gtksee-0.2.0
CATEGORIES=	graphics
MASTER_SITES=   http://www.zg169.net/~hotaru/download/

MAINTAINER=     ibex@physik.TU-Berlin.DE

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		tiff34.1:${PORTSDIR}/graphics/tiff34

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${PREFIX}/include \
		LDFLAGS=-L${PREFIX}/lib

.include <bsd.port.mk>
