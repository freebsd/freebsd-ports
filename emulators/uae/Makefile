# New ports collection makefile for: uae
# Date created: 22 May 2000
# Whom: Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	uae
PORTVERSION=	0.8.20
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/sources/develop/

MAINTAINER=	simond@irrelevant.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sound --enable-vidmode --enable-dga --disable-ui
USE_XLIB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uae ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/readdisk ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/uae
	${INSTALL_DATA} ${WRKSRC}/docs/COMPATIBILITY ${PREFIX}/share/uae
	${INSTALL_DATA} ${WRKSRC}/docs/CREDITS ${PREFIX}/share/uae
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${PREFIX}/share/uae
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${PREFIX}/share/uae
	${INSTALL_DATA} ${WRKSRC}/docs/README ${PREFIX}/share/uae
	${INSTALL_DATA} ${WRKSRC}/docs/README.PROGRAMMERS ${PREFIX}/share/uae
	${INSTALL_DATA} ${WRKSRC}/docs/unix/README ${PREFIX}/share/uae/README.unix
	@${MKDIR} ${PREFIX}/share/uae/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/mousehack ${PREFIX}/share/uae/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/timehack ${PREFIX}/share/uae/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/transdisk ${PREFIX}/share/uae/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/transrom ${PREFIX}/share/uae/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control ${PREFIX}/share/uae/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control.info ${PREFIX}/share/uae/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae_rcli ${PREFIX}/share/uae/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uaectrl ${PREFIX}/share/uae/amiga/

.include <bsd.port.mk>
