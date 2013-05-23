# Created by: Joao Carlos Mendes Luis <jonny@jonny.eng.br>
# $FreeBSD$

PORTNAME=	id3ren
PORTVERSION=	1.1b0
CATEGORIES=	audio
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Rename MP3 files, edit tags, search, etc

LICENSE=	GPLv2

PLIST_FILES=	bin/id3ren
MAN1=		id3ren.1
MANCOMPRESSED=	yes
PORTDOCS=	AUTHORS ChangeLog FEATURES FEEDBACK INSTALL PORTS \
		README THANKS TODO USAGE

.include <bsd.port.options.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/id3ren.c ${WRKSRC}/src/id3misc.c
	${RM} ${WRKSRC}/src/id3ren

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
