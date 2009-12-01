# New ports collection makefile for:	esmska
# Date created:				18 Feb 2008
# Whom:					Martin Otto
#
# $FreeBSD$
#

PORTNAME=	esmska
PORTVERSION=	0.17.0
CATEGORIES=	comms java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gamato@users.sf.net
COMMENT=	Program for sending SMS over the Internet

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.6+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	esmska

PORTDOCS=	readme.txt

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/esmska.jar ${DATADIR}/
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} icons ${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} lib ${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} license ${DATADIR}/)
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} operators ${DATADIR}/)
	${INSTALL_SCRIPT} ${WRKDIR}/esmska ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
