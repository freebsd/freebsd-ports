# New ports collection makefile for:    imaze
# Version required:	1.3
# Date created:         27. April 1996
# Whom:                 Ronald Kuehn <kuehn@rz.tu-clausthal.de>
#
# $Id: Makefile,v 1.9 1998/08/05 09:30:56 asami Exp $
#

DISTNAME=       imaze
PKGNAME=	imaze-1.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/ \
		ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/sounds/
DISTFILES=	imaze1.3.tar.Z imaze.tar

MAINTAINER=	kuehn@rz.tu-clausthal.de

.if defined(HAVE_MOTIF) && !defined(PACKAGE_BUILDING)
MAKE_ENV+=	FORCE_MOTIF=yes
.else
LIB_DEPENDS=	xview\\.3\\.2:${PORTSDIR}/x11-toolkits/xview-lib
.endif

EXTRACT_ONLY=	imaze1.3.tar.Z
USE_X_PREFIX=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}/imaze/Makefile
	@tar xf ${DISTDIR}/imaze.tar -C ${WRKDIR}/imaze

.include <bsd.port.mk>
