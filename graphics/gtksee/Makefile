# New ports collection makefile for:	gtksee
# Date created:		Sun Nov 22 12:08:18 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $FreeBSD$
#

PORTNAME=	gtksee
PORTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.linux.tucows.com/files/x11/graphics/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	bzip:${PORTSDIR}/archivers/bzip \
		bzip2:${PORTSDIR}/archivers/bzip2

USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
