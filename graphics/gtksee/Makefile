# New ports collection makefile for:	gtksee
# Date created:		Sun Nov 22 12:08:18 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $FreeBSD$
#

PORTNAME=	gtksee
PORTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://hotaru.clinuxworld.com/gtksee/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	bzip:${PORTSDIR}/archivers/bzip \
		bzip2:${PORTSDIR}/archivers/bzip2

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${PREFIX}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LDFLAGS=-L${PREFIX}/lib

.include <bsd.port.mk>
