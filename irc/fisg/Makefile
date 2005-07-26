# New ports collection makefile for:    fisg
# Date created:         29 Nov 2004
# Whom:                 Pasi Hirvonen <psh@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	fisg
PORTVERSION=	0.3.12
CATEGORIES=	irc
MASTER_SITES=	http://www.tnsp.org/files/ \
		http://www.daemon.li/distfiles/

MAINTAINER=	psh@iki.fi
COMMENT=	Fast IRC statistics generator

USE_REINPLACE=	yes
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PORTDOCS=	README FAQ
MAN1=		fisg.1

post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX|PREFIX?|' \
	-e 's|^CC|CC?|' -e 's|^CFLAGS|CFLAGS?|' ${WRKSRC}/src/Makefile

do-install:
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/data/*.png ${DATADIR}/
	${CP} -Rp ${WRKSRC}/data/*.css ${DATADIR}/
	${CP} -Rp ${WRKSRC}/data/*.gif ${DATADIR}/
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/users.cfg ${EXAMPLESDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/src/fisg ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/src/fisg.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
