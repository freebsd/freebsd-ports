# New ports collection makefile for: 	hppsmtools
# Date created:		2 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	hppsmtools
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://unimut.fsk.uni-heidelberg.de/demi/photosmart/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for HP PhotoSmart C5340A & Konica Q-EZ digital cameras

USE_REINPLACE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/psmdel bin/psmdir bin/psmget bin/psmsho

post-patch:
	@${REINPLACE_CMD} -e 's|^CC=|#CC=|g ; \
		 s|-Wall -pedantic|$$(CFLAGS)|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/typedef unsigned char/d' ${WRKSRC}/exif.h
	@${REINPLACE_CMD} -e '/<malloc.h>/d' ${WRKSRC}/psm*.c

do-install:
.for file in psmdel psmdir psmget psmsho
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
