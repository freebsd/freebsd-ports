# New ports collection makefile for: gIDE
# Version required:    0.0.11
# Date created:        29 Jul 1998
# Whom:                rom
#
# $Id: Makefile,v 1.13 1998/11/06 12:04:27 asami Exp $
#

DISTNAME= 	gIDE-0.0.11
PKGNAME= 	gide-0.0.11
CATEGORIES=     devel
MASTER_SITES=   http://gide.pn.org/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		guile.4:${PORTSDIR}/lang/guile

USE_X_PREFIX=   yes
GNU_CONFIGURE=  yes
USE_GMAKE= 	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gide.1

.include <bsd.port.mk>
