# New ports collection makefile for:    dtaus
# Date created:         12 Jan 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	dtaus
PORTVERSION=	0.9
CATEGORIES=	german finance
MASTER_SITES=	http://www.infodrom.org/projects/dtaus/download/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Belegloser DatenTraegerAUStausch

ALL_TARGET=	dtaus
PLIST_FILES=	bin/dtaus

PORTDOCS=	ChangeLog README TODO dtaus.txt
PORTEXAMPLES=	dtaus.cls sample.ctl
MAN1=		dtaus.1
MAN5=		dtaus.5

do-configure:
	 ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/bigint.c ${WRKSRC}/dtaus.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dtaus ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dtaus.1  ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/dtaus.5  ${PREFIX}/man/man5/
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} \
		${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for doc in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${doc} \
		${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
