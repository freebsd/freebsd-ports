# New ports collection makefile for:   cosmo
# Version required:    2.0.4
# Date created:        28 December 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/05/25 17:24:02 max Exp $
#

DISTNAME=	cosmo-2.0.4
CATEGORIES=     games
MASTER_SITES=   http://cheer.u-aizu.ac.jp:10080/~eiju/cosmo/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}  moon.tif.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

NO_CDROM=	Possible copyright infringement

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/cosmo2
DIST_SUBDIR=	cosmo
USE_IMAKE=	yes
XMKMF=		xmkmf
NO_INSTALL_MANPAGES=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/cosmorc ${PREFIX}/lib/X11/cosmo
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/moon.tif.gz \
		 ${PREFIX}/lib/X11/cosmo

.include <bsd.port.mk>
