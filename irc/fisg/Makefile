# New ports collection makefile for:    fisg
# Date created:         29 Nov 2004
# Whom:                 Pasi Hirvonen <psh@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	fisg
PORTVERSION=	0.2.0
CATEGORIES=	irc
MASTER_SITES=	http://www.tnsp.org/files/

MAINTAINER=	psh@iki.fi
COMMENT=	Fast IRC statistics generator

USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PORTDOCS=	README FAQ

DATA_FILES=	blue-h.png happy1.gif happy5.gif style-c64.css \
		blue-v.png happy2.gif happy6.gif style-pisg.css \
		green-h.png happy3.gif red-h.png yellow-h.png \
		green-v.png happy4.gif red-v.png yellow-v.png

PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data/ && ${INSTALL_DATA} ${DATA_FILES} ${DATADIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/users.cfg ${EXAMPLESDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/src/fisg ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
