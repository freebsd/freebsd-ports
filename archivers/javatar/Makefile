# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	javatar
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	archivers java
MASTER_SITES=	http://www.gjt.org/download/time/java/tar/ \
		ftp://ftp.gjt.org/pub/time/java/tar/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java tar archive I/O package

RUN_DEPENDS=	${JAVALIBDIR}/activation.jar:${PORTSDIR}/java/jaf

NO_STAGE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes

PORTDOCS=	api LICENSE License.html readme.html tarman.html

JARFILES=	tar.jar
PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

.include <bsd.port.options.mk>

do-install:
	@${ECHO_MSG} -n ">> Install JAR file in ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/jars/tar.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
