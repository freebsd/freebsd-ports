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

CLASSES_SUBDIR=	share/java/classes
STYLE_SUBDIR=	share/java/${PORTNAME}

post-extract:
	@${TOUCH} ${WRKDIR}/PLIST

do-build:
	@(cd ${WRKSRC}; ${SETENV} JAVA_HOME=${JAVA_HOME} ant build.bindist)

do-install:
	@${MKDIR} ${PREFIX}/${CLASSES_SUBDIR}
	@${INSTALL_DATA} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/${PORTNAME}-all-${PORTVERSION}.jar ${PREFIX}/${CLASSES_SUBDIR}/${PORTNAME}.jar
	@${ECHO} ${CLASSES_SUBDIR}/${PORTNAME}.jar >> ${PLIST}
	@${MKDIR} ${PREFIX}/${STYLE_SUBDIR}
	@(cd ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib && \
	  ${TAR} -c -f - .) \
		| (cd ${PREFIX}/${STYLE_SUBDIR} && ${TAR} --unlink -x -f -)
	@cd ${PREFIX} \
		&& ${FIND} ${STYLE_SUBDIR} -type f -print >> ${PLIST}
	@cd ${PREFIX} \
		&& ${FIND} ${STYLE_SUBDIR} -type d -print | sort -r | \
		${SED} "s,^,@dirrm ,g" >> ${PLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION} && \
	  ${TAR} -c --exclude '*.jar' --exclude contrib -f - .) \
		| (cd ${DOCSDIR} && ${TAR} --unlink -x -f -)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@cd ${PREFIX} \
		&& ${FIND} share/doc/${PORTNAME} -type f -print >> ${PLIST}
	@cd ${PREFIX} \
		&& ${FIND} share/doc/${PORTNAME} -type d -print | sort -r | \
		${SED} "s,^,@dirrm ,g" >> ${PLIST}
.endif
	@${ECHO} "@unexec ${RMDIR} %D/${CLASSES_SUBDIR} 2>/dev/null || true" >> ${PLIST}

.include <bsd.port.mk>
