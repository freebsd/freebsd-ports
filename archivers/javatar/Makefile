# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	javatar
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	archivers java
MASTER_SITES=	http://www.gjt.org/download/time/java/tar/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java tar archive I/O package

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes

PORTDOCS=	api LICENSE License.html readme.html tarman.html

JARFILES=	tar.jar
PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

OPTIONS_DEFINE=	DOCS

do-install:
	@${ECHO_MSG} -n ">> Install JAR file in ${STAGEDIR}${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/jars/tar.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${STAGEDIR}${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
