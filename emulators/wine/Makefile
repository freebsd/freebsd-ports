# New ports collection makefile for:    wine
# Version required:     961023
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $Id: Makefile,v 1.34 1996/11/12 02:17:06 obrien Exp $
#

DATE=		961102
DISTNAME=	Wine-${DATE}
PKGNAME=	wine-96.11.02
CATEGORIES=	emulators x11
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/ALPHA/wine/development/ \
		ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/ \
		ftp://ftp.dfv.rwth-aachen.de/pub/linux/sunsite/ALPHA/wine/development/ \
		ftp://ftp.infomagic.com/pub/mirrors/linux/wine/development/ \
		ftp://aris.com/pub/linux/ALPHA/Wine/development/

MAINTAINER=	se@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine${DATE}
GNU_CONFIGURE=	yes
MAN1=		wine.1

pre-configure:
	@${ECHO} "WINE_INI_GLOBAL \"${PREFIX}/etc/wine.conf\"" \
		>> ${WRKSRC}/autoconf.h

post-configure:
		cd ${WRKSRC} && make depend

do-install:
	install -c ${WRKSRC}/wine ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/etc 2>/dev/null
	[ -f ${PREFIX}/etc/wine.conf ] \
		|| ${CP} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf
	cp ${WRKSRC}/wine.sym ${PREFIX}/etc
	cp ${WRKSRC}/wine.man ${PREFIX}/man/man1/wine.1

.include <bsd.port.mk>
