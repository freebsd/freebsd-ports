# New ports collection makefile for:	e-uae
# Date created:				Sun Dec  5 15:03:37 CET 2004
# Whom:					Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	e-uae
PORTVERSION=	0.8.27
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/${PORTNAME}-${PORTVERSION}/ \
		http://www.energyhq.es.eu.org/files/

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Enhanced version of UAE, the Amiga emulator

CONFLICTS=	uae-[0-9]*
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GNOME=	gtk20
USE_SDL=	sdl
USE_REINPLACE=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's@sdl-config@sdl11-config@g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/uae ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/readdisk ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/bsdsocket.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/compiling.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/configuration.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/floppies.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/keyboard.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/scsi.txt ${DOCSDIR}
.endif
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
