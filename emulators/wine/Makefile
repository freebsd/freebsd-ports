# New ports collection makefile for:    wine
# Version required:     980517
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $Id: Makefile,v 1.64 1998/10/13 04:39:18 jseger Exp $
#

DATE=		980927
DISTNAME=	Wine-${DATE}
PKGNAME=	wine-98.09.27
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development

MAINTAINER=	se@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine-${DATE}
GNU_CONFIGURE=	yes
MAN1=		wine.1

post-extract:
	-${MKDIR} ${WRKSRC}/include/asm
	${CP} ${FILESDIR}/bitops.h ${WRKSRC}/include/asm/bitops.h

pre-configure:
	@${ECHO} "WINE_INI_GLOBAL \"${PREFIX}/etc/wine.conf\"" \
		>> ${WRKSRC}/autoconf.h

post-configure:
		cd ${WRKSRC} && make depend

do-install:
	${INSTALL} -c ${WRKSRC}/wine ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/etc 2>/dev/null
	[ -f ${PREFIX}/etc/wine.conf ] \
		|| ${CP} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf
	${CP} ${WRKSRC}/wine.sym ${PREFIX}/etc
	${CP} ${WRKSRC}/documentation/wine.man ${PREFIX}/man/man1/wine.1

.include <bsd.port.mk>
