# New ports collection makefile for: uae
# Date created: 22 May 2000
# Whom: Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	uae
PORTVERSION=	0.8.22
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/sources/develop/

MAINTAINER=	simond@irrelevant.org
COMMENT=	Amiga emulator

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	213
CONFIGURE_ARGS=	--enable-sound --enable-vidmode --enable-dga
USE_XLIB=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes

CFLAGS+=	${PTHREAD_CFLAGS}

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uae ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/readdisk ${PREFIX}/bin
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/COMPATIBILITY ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README.PROGRAMMERS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/unix/README ${DOCSDIR}/README.unix
	@${MKDIR} ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/mousehack ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/timehack ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/transdisk ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/transrom ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control.info ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae_rcli ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uaectrl ${DATADIR}/amiga/

.include <bsd.port.mk>
