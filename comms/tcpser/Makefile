# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpser
DISTVERSION=	1.0rc12
CATEGORIES=	comms
MASTER_SITES=	http://www.jbrain.com/pub/linux/serial/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCPSER turns serial port into an emulated Hayes compatible modem

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

LDFLAGS+=	-pthread
USE_DOS2UNIX=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/tcpser

PORTDOCS=	README CHANGES
PLIST_FILES=	bin/tcpser

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpser ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
