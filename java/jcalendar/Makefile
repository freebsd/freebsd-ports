# ex:ts=8
# Ports collection makefile for:	jcalendar
# Date created:			Apr 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcalendar
PORTVERSION=	1.3.3
CATEGORIES=	java misc
MASTER_SITES=	http://www.toedter.com/download/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Java Date Chooser

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
WRKSRC=		${WRKDIR}/src
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		%%JAVAJARDIR%%/looks-2.0.1.jar

###
# has a potential conflict with devel/looks, both install a looksXXX.jar
###

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-build:
	cd ${WRKDIR}/build && \
		${JAR} cmf ${WRKSRC}/${PORTNAME}.manifest \
			${WRKDIR}/build/${PORTNAME}.jar *

do-install:
	${INSTALL_DATA} ${WRKDIR}/build/${PORTNAME}.jar ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/lib/looks-2.0.1.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
