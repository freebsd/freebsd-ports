# Ports collection makefile for:    Java Checkstyle
# Date created:         2002/09/02
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	checkstyle
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	java-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	dglo@ssec.wisc.edu
COMMENT=	Java style checker

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.3+
NEED_JAVAC=	YES

PLIST=	${WRKDIR}/PLIST

JAVALIBNAME=	${PORTNAME}-${PORTVERSION}
APIDOCSDIR=	${DOCSDIR}/javadoc
STYLEDIR=	${JAVASHAREDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@${ECHO} ${JAVAJARDIR}/${PORTNAME}.jar | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${ECHO} ${JAVAJARDIR}/${PORTNAME}-optional.jar | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${ECHO} "@unexec ${RMDIR} ${JAVAJARDIR} 2>/dev/null || true" | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${FIND} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib/ \
		-type f -print | \
		${SED} "s,${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib/,${STYLEDIR}/," | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${FIND} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib/ \
		-type d -print | ${SORT} -r | \
		${SED} "s,${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib/,${STYLEDIR}/," | \
		${SED} -e "s,${PREFIX}/*,," -e "s,^,@dirrm ,g" >> ${PLIST}

do-build:
	@cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} ant build.bindist

do-install: do-install-jar do-install-data do-install-apidocs

do-install-jar:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/${PORTNAME}-all-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${INSTALL_DATA} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/${PORTNAME}-${PORTVERSION}-optional.jar ${JAVAJARDIR}/${PORTNAME}-optional.jar

do-install-data:
	@${MKDIR} ${STYLEDIR}
	@${CP} -r ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib/* ${STYLEDIR}

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${APIDOCSDIR}
	@(cd ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION} && \
		${TAR} -c --exclude '*.jar' --exclude contrib -f - .) | \
		(cd ${APIDOCSDIR} && ${TAR} --unlink -x -f -)
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${APIDOCSDIR}
.endif

.include <bsd.port.mk>
