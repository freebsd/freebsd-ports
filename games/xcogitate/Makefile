# New ports collection makefile for:	xcogitate
# Version required:			1.02
# Date created:				15 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/04/28 03:30:19 mph Exp $
#

DISTNAME=	xcogitate-1.02
CATEGORIES=	games
MASTER_SITES=	http://www.freebsd.org/~mph/distfiles/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
WRKSRC=		${WRKDIR}/XCOGITATE_SOURCE

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${X11BASE}/include -o xcogitate xcogitate.c -L${X11BASE}/lib -lX11 -lXpm

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xcogitate ${PREFIX}/bin

.include <bsd.port.mk>
