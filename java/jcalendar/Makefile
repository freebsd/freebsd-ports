# Created by: ijliao
# $FreeBSD$

PORTNAME=	jcalendar
PORTVERSION=	1.3.3
CATEGORIES=	java misc
MASTER_SITES=	http://www.toedter.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Date Chooser

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
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

NO_STAGE=	yes
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
