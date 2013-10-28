# $FreeBSD$

PORTNAME=	dtaus
PORTVERSION=	0.9
CATEGORIES=	german finance
MASTER_SITES=	http://www.infodrom.org/projects/dtaus/download/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Belegloser DatenTraegerAUStausch

LICENSE=	GPLv2

ALL_TARGET=	dtaus
PLIST_FILES=	bin/dtaus man/man1/dtaus.1.gz man/man5/dtaus.5.gz
PORTDOCS=	ChangeLog README TODO dtaus.txt
PORTEXAMPLES=	dtaus.cls sample.ctl

.include <bsd.port.options.mk>

do-configure:
	 ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/bigint.c ${WRKSRC}/dtaus.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dtaus ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dtaus.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/dtaus.5 ${STAGEDIR}${MANPREFIX}/man/man5/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} \
		${STAGEDIR}${DOCSDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for doc in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${doc} \
		${STAGEDIR}${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
