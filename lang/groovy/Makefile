# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	groovy
DISTVERSION=	2.0.5
CATEGORIES=	lang java
MASTER_SITES=	http://dist.groovy.codehaus.org/distributions/
DISTNAME=	groovy-${PORTVERSION}
DISTFILES=	groovy-binary-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mjs@Bur.st
COMMENT=	Agile dynamic language for the JVM

LICENSE=	AL2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:U}

USE_ZIP=yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	ANTLR-LICENSE.txt ASM-LICENSE.txt CLI-LICENSE.txt JSR223-LICENSE.txt LICENSE.txt conf lib
SCRIPTFILES=	groovy groovyConsole groovyc groovysh java2groovy startGroovy

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	groovy-docs-${PORTVERSION}${EXTRACT_SUFX}
PORTDOCS=	html pdf
.endif
PLIST_FILES=	${SCRIPTFILES:S,^,bin/,} %%JAVAJARDIR%%/${PORTNAME}.jar
SUB_FILES=	set-groovy_home.sed

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/embeddable/${PORTNAME}-all-${DISTVERSION:U}.jar ${JAVAJARDIR}/${PORTNAME}.jar
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
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
