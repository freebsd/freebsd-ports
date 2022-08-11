PORTNAME=	voipong
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.enderunix.org/voipong/

MAINTAINER=	siseci@EnderUNIX.org
COMMENT=	Detect Voice Over IP calls and dump them to separate wave files

USE_LDCONFIG=	yes
PORTDOCS=	ALGORITHMS AUTHORS ChangeLog COPYING INSTALL KNOWN_BUGS \
		LICENSE  NEWS README THANKS TODO
MAKEFILE=	Makefile.bsd

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/users-manual
	${INSTALL_DATA} ${WRKSRC}/docs/users-manual/*.html ${STAGEDIR}${DOCSDIR}/users-manual/
	${INSTALL_DATA} ${WRKSRC}/docs/users-manual/*.css ${STAGEDIR}${DOCSDIR}/users-manual/
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
