PORTNAME=	id3ren
PORTVERSION=	1.1b0
CATEGORIES=	audio

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Rename MP3 files, edit tags, search, etc

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	sebcode
GH_TAGNAME=	322ee77

PLIST_FILES=	bin/id3ren man/man1/id3ren.1.gz
PORTDOCS=	AUTHORS ChangeLog FEATURES FEEDBACK INSTALL PORTS \
		README THANKS TODO USAGE

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/id3ren.c ${WRKSRC}/src/id3misc.c
	${RM} ${WRKSRC}/src/id3ren

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1.gz \
		${STAGEDIR}${PREFIX}/man/man1/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
