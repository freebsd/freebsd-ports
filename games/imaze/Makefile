# New ports collection makefile for:    imaze
# Version required:	1.3
# Date created:         27. April 1996
# Whom:                 Ronald Kuehn <kuehn@rz.tu-clausthal.de>
#
#

DISTNAME=       imaze
DISTFILES=	imaze1.3.tar.Z imaze.tar
PKGNAME=	imaze-1.3
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/ \
		ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/sounds/
EXTRACT_ONLY=	imaze1.3.tar.Z
LIB_DEPENDS=	xview\\.3\\.2:${PORTSDIR}/x11/xview-lib

MAINTAINER=	kuehn@rz.tu-clausthal.de

NO_CONFIGURE=	yes
USE_X11=	yes
NO_CDROM=	yes

post-extract:
	@cp ${FILESDIR}/Makefile ${WRKDIR}/imaze/Makefile
	@tar xf ${DISTDIR}/imaze.tar -C ${WRKDIR}/imaze

.include <bsd.port.mk>
