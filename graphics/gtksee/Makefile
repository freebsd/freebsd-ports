# New ports collection makefile for:	gtksee
# Version required:	0.1.4
# Date created:		Sun Nov 22 12:08:18 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $Id: Makefile,v 1.11 1999/04/22 07:39:06 mharo Exp $
#

DISTNAME=	gtksee-0.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.zg169.net/~hotaru/gtksee/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.ORG

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34
RUN_DEPENDS=	bzip:${PORTSDIR}/archivers/bzip \
		bzip2:${PORTSDIR}/archivers/bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${PREFIX}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		LDFLAGS=-L${PREFIX}/lib

.include <bsd.port.mk>
