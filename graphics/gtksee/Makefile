# New ports collection makefile for:	gtksee
# Version required:	0.1.4
# Date created:		Sun Nov 22 12:08:18 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $Id: Makefile,v 1.7 1998/12/25 14:41:09 vanilla Exp $
#

DISTNAME=	gtksee-0.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.pressroom.com/~mrc/gtksee/ \
		http://www.zg169.net/~hotaru/gtksee/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.ORG

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${PREFIX}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LDFLAGS=-L${PREFIX}/lib

.include <bsd.port.mk>
