# Ports collection makefile for:    Java Checkstyle
# Date created:         2002/09/02
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	checkstyle
PORTVERSION=	3.4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	java-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	dglo@ssec.wisc.edu
COMMENT=	Java style checker

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.4+

PLIST=	${WRKDIR}/PLIST

JAVALIBNAME=	${PORTNAME}-${PORTVERSION}
STYLEDIR=	${JAVASHAREDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
BUILTDOCSDIR=	${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}
BUILTDOCS=	README LICENSE* TODO RIGHTS* docs
PORTDOCS=	*
.endif

do-build:
	@cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} ant build.bindist

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

do-install: do-install-jar do-install-data do-install-apidocs

do-install-jar:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/${PORTNAME}-all-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${INSTALL_DATA} ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/${PORTNAME}-optional-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}-optional.jar

do-install-data:
	@${MKDIR} ${STYLEDIR}
	@${CP} -r ${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}/contrib/* ${STYLEDIR}

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${BUILTDOCS}
	@${CP} -r ${BUILTDOCSDIR}/${DOCFILE} ${DOCSDIR}/
.endfor
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
