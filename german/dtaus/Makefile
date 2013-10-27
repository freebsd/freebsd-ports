# $FreeBSD$

PORTNAME=	dtaus
PORTVERSION=	0.9
CATEGORIES=	german finance
MASTER_SITES=	http://www.infodrom.org/projects/dtaus/download/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Belegloser DatenTraegerAUStausch

LICENSE=	GPLv2

USES=		manpages:install
ALL_TARGET=	dtaus
PLIST_FILES=	bin/dtaus
PORTDOCS=	ChangeLog README TODO dtaus.txt
PORTEXAMPLES=	dtaus.cls sample.ctl
MAN1=		dtaus.1
MAN5=		dtaus.5

.include <bsd.port.options.mk>

do-configure:
	 ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/bigint.c ${WRKSRC}/dtaus.c

do-install:	install-all-manpages
	${INSTALL_PROGRAM} ${WRKSRC}/dtaus ${STAGEDIR}${PREFIX}/bin/
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
