# Ports collection makefile for:    Java Checkstyle
# Date created:         2002/09/02
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	checkstyle
PORTVERSION=	2.4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	java-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	dglo@ssec.wisc.edu

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/jakarta-ant

USE_JAVA=	1.2+
NEED_JAVAC=	YES

PLIST=	${WRKDIR}/PLIST

JAVALIBNAME=	${PORTNAME}-${PORTVERSION}
APIDOCSDIR=	${DOCSDIR}/${JAVALIBNAME}
STYLEDIR=	${JAVASHAREDIR}/${PORTNAME}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}

do-build:
	@cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} ant build.bindist

do-install: do-install-jar do-install-data do-install-apidocs

do-install-jar:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/${PORTNAME}-all-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO} ${JAVAJARDIR}/${PORTNAME}.jar | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${ECHO} "@unexec ${RMDIR} ${JAVAJARDIR} 2>/dev/null || true" | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}

do-install-data:
	@${MKDIR} ${STYLEDIR}
	@${CP} -r ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib/* ${STYLEDIR}
	@${FIND} ${STYLEDIR} -type f -print | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${FIND} ${STYLEDIR} -type d -print | sort -r | \
		${SED} -e "s,${PREFIX}/*,," -e "s,^,@dirrm ,g" >> ${PLIST}

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${APIDOCSDIR}
	@(cd ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION} && \
		${TAR} -c --exclude '*.jar' --exclude contrib -f - .) | \
		(cd ${APIDOCSDIR} && ${TAR} --unlink -x -f -)
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${APIDOCSDIR}
	@${FIND} ${APIDOCSDIR} -type f -print | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${FIND} ${APIDOCSDIR} -type d -print | sort -r | \
		${SED} -e "s,${PREFIX}/*,," -e "s,^,@dirrm ,g" >> ${PLIST}
.endif

.include <bsd.port.mk>
