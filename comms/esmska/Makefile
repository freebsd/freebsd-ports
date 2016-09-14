# Created by: Martin Otto
# $FreeBSD$

PORTNAME=	esmska
PORTVERSION=	0.21
CATEGORIES=	comms java
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	gamato@users.sf.net
COMMENT=	Program for sending SMS over the Internet

BROKEN=		Unfetchable (google code has gone away)

USE_JAVA=	yes
JAVA_VERSION=	1.6+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	esmska

PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/esmska.jar ${STAGEDIR}${DATADIR}/
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} gateways ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} icons ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} license ${STAGEDIR}${DATADIR}/)
	${INSTALL_SCRIPT} ${WRKDIR}/esmska ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
