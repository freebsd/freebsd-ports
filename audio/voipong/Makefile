# Created by: Necati Ersen SISECI <siseci@enderunix.org>
# $FreeBSD$

PORTNAME=	voipong
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.enderunix.org/voipong/

MAINTAINER=	siseci@EnderUNIX.org
COMMENT=	Detect Voice Over IP calls and dump them to separate wave files

USE_LDCONFIG=	yes
PORTDOCS=	ALGORITHMS AUTHORS ChangeLog COPYING INSTALL KNOWN_BUGS \
		LICENSE  NEWS README THANKS TODO
NO_STAGE=	yes

.include <bsd.port.options.mk>
post-patch:
	${MV} ${WRKSRC}/Makefile.bsd ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/users-manual
	${INSTALL_DATA} ${WRKSRC}/docs/users-manual/*.html ${DOCSDIR}/users-manual/
	${INSTALL_DATA} ${WRKSRC}/docs/users-manual/*.css ${DOCSDIR}/users-manual/
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
