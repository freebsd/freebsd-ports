# New ports collection makefile for:	xcogitate
# Version required:			1.02
# Date created:				15 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	xcogs
PKGNAME=	xcogitate-1.02
CATEGORIES=	games x11
# Fetch truncates the file when retrieved from...
# MASTER_SITES=	http://www.pff-software.demon.nl/archive/
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

BROKEN=		Waiting for distfile to be moved to MASTER_SITE_LOCAL

USE_X11=	yes
WRKSRC=		${WRKDIR}/XCOGITATE_SOURCE

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${X11BASE}/include -o xcogitate xcogitate.c -L${X11BASE}/lib -lX11 -lXpm

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xcogitate ${PREFIX}/bin

.include <bsd.port.mk>
