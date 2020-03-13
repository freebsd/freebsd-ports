# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	groovy
DISTVERSION=	2.4.19
CATEGORIES=	lang java
MASTER_SITES=	http://dl.bintray.com/groovy/maven/
DISTFILES=	apache-groovy-binary-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Agile dynamic language for the JVM

LICENSE=	APACHE20

USES=		zip
USE_JAVA=	yes

NO_ARCH=	yes
NO_BUILD=	yes

DATAFILES=	conf lib
PLIST_FILES=	${SCRIPTFILES:S,^,bin/,} ${JAVAJARDIR}/${PORTNAME}.jar
PORTDOCS=	html
SCRIPTFILES=	groovy groovyConsole groovyc groovysh java2groovy startGroovy
SUB_FILES=	set-groovy_home.sed

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:tu}

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	apache-groovy-docs-${PORTVERSION}${EXTRACT_SUFX}

do-install:
	@${ECHO_MSG} -n ">> Staging JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	${INSTALL_DATA} ${WRKSRC}/embeddable/${PORTNAME}-all-${DISTVERSION:tu}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Staging data files in ${DATADIR}..."
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Staging executables in ${PREFIX}/bin..."
	@${REINPLACE_CMD} -f ${WRKDIR}/set-groovy_home.sed ${WRKSRC}/bin/startGroovy
.for file in ${SCRIPTFILES}
	@${ECHO_MSG} -n " ${file}"
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${STAGEDIR}${PREFIX}/bin/
.endfor
	@${ECHO_MSG} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Staging documentation in ${DOCSDIR}..."
	@cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},@dir ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dir ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
