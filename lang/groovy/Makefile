# New ports collection makefile for:	groovy
# Date created:				2005-02-21
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	groovy
DISTVERSION=	1.0-jsr-04
CATEGORIES=	lang java
MASTER_SITES=	http://dist.codehaus.org/groovy/distributions/

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Agile dynamic language for the JVM

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	LICENSE.txt conf ${PORTNAME}-${DISTVERSION}.jar lib
SCRIPTFILES=	grok groovy groovyConsole groovyc groovysh startGroovy

.if !defined(NOPORTDOCS)
PORTDOCS=	changelog-report.html cvs-usage.html dependencies.html \
		developer-activity-report.html downloads.html faq.html \
		file-activity-report.html groovy-jdk.html images index.html \
		issue-tracking.html jdepend-report.html junit-report.html \
		license.html mail-lists.html maven-reports.html \
		pmd-report.html project-info.html style team-list.html xref \
		xref-test
.endif
PLIST_FILES=	${SCRIPTFILES:S,^,bin/,} %%JAVAJARDIR%%/${PORTNAME}.jar
SUB_FILES=	set-groovy_home.sed

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/embeddable/${PORTNAME}-all-${DISTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing data files in ${DATADIR}..."
	@cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing executables in ${PREFIX}/bin..."
	@${REINPLACE_CMD} -f ${WRKDIR}/set-groovy_home.sed ${WRKSRC}/bin/startGroovy
.for file in ${SCRIPTFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${PREFIX}/bin/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/docs \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
