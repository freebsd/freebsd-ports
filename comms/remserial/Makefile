# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	remserial
PORTVERSION=	1.4
CATEGORIES=	comms
MASTER_SITES=	http://lpccomp.bc.ca/remserial/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bridge between a TCP/IP network port and a character-oriented device

USES=		dos2unix

PLIST_FILES=	bin/remserial
PORTDOCS=	README.txt

CFLAGS+=	-DOSVERSION=\"${OSVERSION}\"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
