# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	violet
PORTVERSION=	2.1.0
CATEGORIES=	devel editors java
MASTER_SITES=	SF/${PORTNAME}/violetumleditor/${PORTVERSION}
DISTNAME=	violetumleditor-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to learn and use UML editor

LICENSE=	GPLv2

USE_JAVA=	yes

NO_BUILD=	YES

PLIST_FILES=	%%JAVASHAREDIR%%/${PORTNAME}/violetumleditor.jar bin/${PORTNAME}

pre-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/violet.sh
	${ECHO} "${PREFIX}/bin/java -jar ${JAVASHAREDIR}/${PORTNAME}/violetumleditor.jar" >> ${WRKDIR}/violet.sh

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/violetumleditor-${PORTVERSION}.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/violetumleditor.jar
	${INSTALL_SCRIPT} ${WRKDIR}/violet.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
