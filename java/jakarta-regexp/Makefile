# Ports collection makefile for:    Jakarta Regexp
# Date created:         2000/12/01
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu> #
# $FreeBSD$
#

PORTNAME=	jakarta-regexp
PORTVERSION=	1.2
CATEGORIES=	java
MASTER_SITES=	http://www.apache.org/dist/jakarta/regexp/

MAINTAINER=	dglo@ssec.wisc.edu

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/jakarta-ant

USE_JAVA=	1.2+
NEED_JAVAC=	YES

PLIST=	${WRKDIR}/PLIST

JAVALIBNAME=	${PORTNAME}-${PORTVERSION}
APIDOCSDIR=	${DOCSDIR}/${JAVALIBNAME}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}

do-build:
	@cd ${WRKSRC}/build && \
		${SETENV} PATH=$$PATH:${JAVA_HOME}/bin JAVA_HOME=${JAVA_HOME} ${SH} build-regexp.sh package

do-install: do-install-jar do-install-apidocs

do-install-jar:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO} ${JAVAJARDIR}/${PORTNAME}.jar | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${ECHO} "@unexec ${RMDIR} ${JAVAJARDIR} 2>/dev/null || true" | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${APIDOCSDIR}
	@${CP} -r ${WRKSRC}/docs/api/* ${APIDOCSDIR}
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${APIDOCSDIR}
	@${FIND} ${APIDOCSDIR} -type f -print | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${FIND} ${APIDOCSDIR} -type d -print | sort -r | \
		${SED} -e "s,${PREFIX}/*,," -e "s,^,@dirrm ,g" >> ${PLIST}
.endif

.include <bsd.port.mk>
