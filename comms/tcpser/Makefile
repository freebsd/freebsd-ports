# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>

PORTNAME=	tcpser
DISTVERSION=	20210425
CATEGORIES=	comms

MAINTAINER=	nc@FreeBSD.org
COMMENT=	TCPSER turns serial port into an emulated Hayes compatible modem

LICENSE=	GPLv2+

USE_GITHUB=	yes
GH_ACCOUNT=	FozzTexx
GH_TAGNAME=	95f4b51

LDFLAGS+=	-pthread
USES=		gmake

PORTDOCS=	README.md CHANGES
PLIST_FILES=	bin/tcpser

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpser ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
