# New ports collection makefile for: gIDE
# Version required:    0.0.4
# Date created:        29 Jul 1998
# Whom:                rom
#
# $Id$
#

DISTNAME= 	gIDE-0.0.4
CATEGORIES=     devel
MASTER_SITES=   http://gide.pn.org/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS+=   gtk\\.1\\.4:${PORTSDIR}/x11/gtk

USE_X11=        yes
GNU_CONFIGURE=  yes
USE_GMAKE= 	yes

post-install:
	strip ${PREFIX}/bin/gide

MAN1=		gide.1

.include <bsd.port.mk>
