# New ports collection makefile for: gIDE
# Version required:    0.0.7
# Date created:        29 Jul 1998
# Whom:                rom
#
# $Id: Makefile,v 1.5 1998/09/15 12:05:11 vanilla Exp $
#

DISTNAME= 	gIDE-0.0.7
PKGNAME= 	gide-0.0.7
CATEGORIES=     devel
MASTER_SITES=   http://gide.pn.org/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		guile\\.2\\.:${PORTSDIR}/lang/guile

USE_X_PREFIX=   yes
GNU_CONFIGURE=  yes
USE_GMAKE= 	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gide.1

post-install:
	strip ${PREFIX}/bin/gide

.include <bsd.port.mk>
