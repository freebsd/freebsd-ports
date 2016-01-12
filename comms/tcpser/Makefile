# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpser
DISTVERSION=	1.0rc12
CATEGORIES=	comms
MASTER_SITES=	http://www.jbrain.com/pub/linux/serial/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCPSER turns serial port into an emulated Hayes compatible modem

LICENSE=	GPLv2+

LDFLAGS+=	-pthread
USES=		dos2unix gmake
WRKSRC=		${WRKDIR}/tcpser

PORTDOCS=	README CHANGES
PLIST_FILES=	bin/tcpser

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpser ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
