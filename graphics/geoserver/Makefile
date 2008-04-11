# New ports collection makefile for:	geoserver
# Date created:				10 March 2008
# Whom:					Wen heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geoserver
PORTVERSION=	1.6.3
CATEGORIES=	graphics geography java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open Source GIS Server

USE_JAVA=	yes
USE_ZIP=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/geoserver
GEOSERVERDIR=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

USE_RC_SUBR=	geoserver.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|$$GEOSERVER_HOME|${GEOSERVERDIR}|g' \
	    ${WRKSRC}/bin/startup.sh ${WRKSRC}/bin/shutdown.sh

pre-install:
	@${FIND} ${WRKSRC} -name "*.bak" -o -name "*.orig" | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${GEOSERVERDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${GEOSERVERDIR}/
	@${CHMOD} -R 755 ${GEOSERVERDIR}

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.post.mk>
