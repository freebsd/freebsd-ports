# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	remserial
PORTVERSION=	1.4
CATEGORIES=	comms
MASTER_SITES=	http://lpccomp.bc.ca/remserial/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bridge between a TCP/IP network port and a character-oriented device

USE_DOS2UNIX=	yes

PLIST_FILES=	bin/remserial
PORTDOCS=	README.txt

CFLAGS+=	-DOSVERSION=\"${OSVERSION}\"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
