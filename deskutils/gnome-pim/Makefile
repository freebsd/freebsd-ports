# New ports collection makefile for:	gnomepim
# Version required:			0.99.3
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	gnome-pim-0.99.3
PKGNAME=	gnomepim-0.99.3
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/latest/ \
		ftp://ftp.geo.net/pub/gnome/sources/latest/ \
		ftp://gnomeftp.wgn.net/pub/gnome/sources/latest/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/latest/

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
