# New ports collection makefile for: gIDE
# Version required:    0.0.4
# Date created:        29 Jul 1998
# Whom:                rom
#
# $Id: Makefile,v 1.2 1998/08/05 09:30:47 asami Exp $
#

DISTNAME= 	gIDE-0.0.4
CATEGORIES=     devel
MASTER_SITES=   http://gide.pn.org/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=    gtk\\.1\\.4:${PORTSDIR}/x11-toolkits/gtk

USE_X_PREFIX=   yes
GNU_CONFIGURE=  yes
USE_GMAKE= 	yes

post-install:
	strip ${PREFIX}/bin/gide

MAN1=		gide.1

.include <bsd.port.mk>
