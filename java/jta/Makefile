# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jta
PORTVERSION=	1.0.1
CATEGORIES=	java devel
MASTER_SITES=	#
DISTNAME=	${PORTNAME}-spec${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Transaction API (JTA)

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
NO_CDROM=	See the license
DOWNLOAD_URL=	http://download.oracle.com/otndocs/jcp/7286-jta-${PORTVERSION}-spec-oth-JSpec/?submit=Download

PORTDOCS=	${DISTNAME}.pdf javadocs

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		you must manually fetch the distribution from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again
.endif

do-install:
	@${ECHO_MSG} -n ">> Install JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
