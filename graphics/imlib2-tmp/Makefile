# New ports collection makefile for:	imlib
# Version required:	1.9.1
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.40 1999/01/14 16:53:36 vanilla Exp $
#

DISTNAME=	imlib-1.9.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/latest/ \
		ftp://ftp.geo.net/pub/gnome/sources/latest/ \
		ftp://gnomeftp.wgn.net/pub/gnome/sources/latest/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/latest/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=    png.2:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		gif.3:${PORTSDIR}/graphics/giflib \
		gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		INSTALL="$${INSTALL} -c"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
