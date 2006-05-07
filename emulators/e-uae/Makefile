# New ports collection makefile for:	e-uae
# Date created:				Sun Dec  5 15:03:37 CET 2004
# Whom:					Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	e-uae
DISTVERSION=	0.8.28
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/${DISTNAME}/ \
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

PLIST_FILES=	bin/uae bin/readdisk
PORTDOCS=	README bsdsocket.txt compiling.txt configuration.txt \
		floppies.txt keyboard.txt scsi.txt

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|' \
		${WRKSRC}/configure

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

.include <bsd.port.mk>
