# New ports collection makefile for:  xrolo
# Version required:    2.6
# Date created:        17 January 1999
# Whom:                Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $Id$
#

DISTNAME=	xrolo.v2p6
PKGNAME=	xrolo-2.6
CATEGORIES=	deskutils
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/X11-contrib/	\
		ftp://ftp.postech.ac.kr/pub/X11/R5contrib/	\
		ftp://ftp.uni-potsdam.de/pub/X11/open-look/	\
		ftp://ftp.khoral.com/pub/dist/X/X11R5.contrib/	\
		ftp://ftp.imag.fr/pub1/x11/xrolo/		\
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

LIB_DEPENDS=    xview.3:${PORTSDIR}/x11-toolkits/xview-lib

WRKSRC=		${WRKDIR}/xrolo

USE_IMAKE=	yes
MAN1=		xrolo.1

.include <bsd.port.mk>
