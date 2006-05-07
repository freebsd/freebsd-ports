# ex:ts=8
# Ports collection makefile for:	jcalendar
# Date created:			Apr 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcalendar
PORTVERSION=	1.2.2
CATEGORIES=	java
MASTER_SITES=	http://www.toedter.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Date Chooser

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
WRKSRC=		${WRKDIR}/src
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		%%JAVAJARDIR%%/looks-${PORTVERSION}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-build:
	cd ${WRKDIR}/build && \
		${JAR} cmf ${WRKSRC}/${PORTNAME}.manifest \
			${WRKDIR}/build/${PORTNAME}.jar *

do-install:
	${INSTALL_DATA} ${WRKDIR}/build/${PORTNAME}.jar ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/lib/looks-${PORTVERSION}.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
