# New ports collection makefile for:    wine
# Version required:     951212
# Date created:         Fri Oct  6 23:43:28 MET 1995
# Whom:			se
#
# $Id: Makefile,v 1.20 1996/02/02 22:51:38 se Exp $
#

DATE=		960218
DISTNAME=	Wine-${DATE}
PKGNAME=	wine-96.02.18
CATEGORIES+=	emulators x11
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/ALPHA/wine/ \
		ftp://aris.com/pub/linux/ALPHA/Wine/development/ \
		ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/ \
		ftp://ftp.dfv.rwth-aachen.de/pub/linux/sunsite/ALPHA/wine/ \
		ftp://ftp.infomagic.com/pub/mirrors/linux/wine/development/

MAINTAINER=	se@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine${DATE}
GNU_CONFIGURE=	yes

pre-configure:
	@echo "WINE_INI_GLOBAL \"${PREFIX}/etc/wine.conf\"" \
		>> ${WRKSRC}/autoconf.h

do-install:
	install -c ${WRKSRC}/wine ${PREFIX}/bin
	-@mkdir ${PREFIX}/etc 2>/dev/null
	[ -f ${PREFIX}/etc/wine.conf ] \
		|| cp ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf
	cp ${WRKSRC}/wine.sym ${PREFIX}/etc
	cp ${WRKSRC}/wine.man ${PREFIX}/man/man1/wine.1
	gzip -9f ${PREFIX}/man/man1/wine.1

.include <bsd.port.mk>
