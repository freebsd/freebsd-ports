# New ports collection makefile for:	tcpser
# Date created:		2008-09-24
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcpser
DISTVERSION=	1.0rc12
CATEGORIES=	comms
MASTER_SITES=	http://www.jbrain.com/pub/linux/serial/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCPSER turns serial port into an emulated Hayes compatible modem

WRKSRC=		${WRKDIR}/tcpser
USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV+=	LDFLAGS=${PTHREAD_LIBS}
PORTDOCS=	README CHANGES
PLIST_FILES=	bin/tcpser

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/tcpser ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/CHANGES ${DOCSDIR}
.endif

.include <bsd.port.mk>
