# New ports collection makefile for:    imaze
# Version required:	1.3
# Date created:         27. April 1996
# Whom:                 Ronald Kuehn <kuehn@rz.tu-clausthal.de>
#
#

DISTNAME=       imaze
PKGNAME=	imaze-1.3
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/ \
		ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/sounds/
DISTFILES=	imaze1.3.tar.Z imaze.tar

MAINTAINER=	kuehn@rz.tu-clausthal.de

LIB_DEPENDS=	xview\\.3\\.2:${PORTSDIR}/x11/xview-lib

EXTRACT_ONLY=	imaze1.3.tar.Z
NO_CONFIGURE=	yes
USE_X11=	yes

post-extract:
	@cp ${FILESDIR}/Makefile ${WRKDIR}/imaze/Makefile
	@tar xf ${DISTDIR}/imaze.tar -C ${WRKDIR}/imaze

.include <bsd.port.mk>
