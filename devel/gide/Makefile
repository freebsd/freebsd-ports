# New ports collection makefile for: gIDE
# Version required:    0.0.8
# Date created:        29 Jul 1998
# Whom:                rom
#
# $Id: Makefile,v 1.7 1998/10/04 17:23:34 jseger Exp $
#

DISTNAME= 	gIDE-0.0.8
PKGNAME= 	gide-0.0.8
CATEGORIES=     devel
MASTER_SITES=   http://gide.pn.org/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		guile.2.:${PORTSDIR}/lang/guile

USE_X_PREFIX=   yes
GNU_CONFIGURE=  yes
USE_GMAKE= 	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gide.1

.include <bsd.port.mk>
