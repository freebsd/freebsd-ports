# New ports collection makefile for:	gIDE
# Version required:			0.0.14
# Date created:				29 Jul 1998
# Whom:					rom
#
# $Id: Makefile,v 1.17 1998/11/16 17:23:05 vanilla Exp $
#

DISTNAME= 	gIDE-0.0.14
PKGNAME= 	gide-0.0.14
CATEGORIES=	devel
MASTER_SITES=	http://gide.pn.org/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gnomeui.1:${PORTSDIR}/x11/gnomelibs \
		guile.4:${PORTSDIR}/lang/guile

USE_X_PREFIX=   yes
USE_GMAKE= 	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gide.1

.include <bsd.port.mk>
