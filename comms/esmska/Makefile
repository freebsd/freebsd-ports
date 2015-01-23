# Created by: Martin Otto
# $FreeBSD$

PORTNAME=	esmska
PORTVERSION=	0.21
CATEGORIES=	comms java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gamato@users.sf.net
COMMENT=	Program for sending SMS over the Internet

USE_JAVA=	yes
JAVA_VERSION=	1.6+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	esmska

PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/esmska.jar ${STAGEDIR}${DATADIR}/
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} gateways ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} icons ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} license ${STAGEDIR}${DATADIR}/)
	${INSTALL_SCRIPT} ${WRKDIR}/esmska ${STAGEDIR}${PREFIX}/bin/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
