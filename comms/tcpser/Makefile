# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpser
DISTVERSION=	1.0rc12
CATEGORIES=	comms
MASTER_SITES=	http://www.jbrain.com/pub/linux/serial/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCPSER turns serial port into an emulated Hayes compatible modem

WRKSRC=		${WRKDIR}/tcpser
USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
PORTDOCS=	README CHANGES
PLIST_FILES=	bin/tcpser

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpser ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/CHANGES ${DOCSDIR}
.endif

.include <bsd.port.mk>
