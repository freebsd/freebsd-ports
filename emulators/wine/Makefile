# New ports collection makefile for:    wine
# Version required:     951003
# Date created:         Fri Oct  6 23:43:28 MET 1995
# Whom:			se
#
# $Id: Makefile,v 1.10 1995/10/05 20:50:32 hsu Exp $
#

DATE=		951003
DISTNAME=       Wine-${DATE}
PKGNAME=	Wine-95.10.03
CATEGORIES+=	emulation x11
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/ALPHA/wine/ \
		ftp://aris.com/pub/linux/ALPHA/Wine/development/ \
		ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/ \
		ftp://ftp.funet.fi/pub/OS/Linux/ALPHA/Wine/ \
		ftp://ftp.infomagic.com/pub/mirrors/linux/wine/development/

MAINTAINER=	se@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine${DATE}
GNU_CONFIGURE=	yes

pre-configure:
	@echo "WINE_INI_GLOBAL \"${PREFIX}/etc/wine.conf\"" \
		>> ${WRKSRC}/autoconf.h

install:
	install -cs ${WRKSRC}/wine ${PREFIX}/bin
	-@mkdir ${PREFIX}/etc 2>/dev/null
	[ -f ${PREFIX}/etc/wine.conf ] \
		|| cp ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf
	cp ${WRKSRC}/wine.sym ${PREFIX}/etc
	cp ${WRKSRC}/Wine.man ${PREFIX}/man/man1/wine.1
	gzip -9f ${PREFIX}/man/man1/wine.1

.include <bsd.port.mk>
