# Created by: jjuanino@gmail.com
# $FreeBSD$

PORTNAME=	sqldeveloper
PORTVERSION=	4.1.1.19.59
DISTVERSIONSUFFIX=-no-jre
CATEGORIES=	databases java
MASTER_SITES=	#http://www.oracle.com/technetwork/developer-tools/sql-developer/overview/index.html
DIST_SUBDIR=	oracle

MAINTAINER=	mizhka@gmail.com
COMMENT=	Graphical tool for database development

RUN_DEPENDS=	bash:shells/bash

USES=		zip
USE_JAVA=	yes

JAVA_VERSION=	1.8+

NO_BUILD=	yes

RESTRICTED=	Packaging prohibited by Oracle license

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} PORTNAME=${PORTNAME}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	due to Oracle license restrictions, you must fetch the source \
distribution manually. Please access \
http://www.oracle.com/technetwork/developer-tools/sql-developer/downloads/index.html \
with a web browser and follow the link for the ${DISTFILES}. You will be \
required to register and log in, but you can create an account on that \
page. After registration and accepting the Oracle License, download the \
distribution file, ${DISTFILES}, into ${DISTDIR}/${DIST_SUBDIR}/ and then \
restart this installation
.endif

do-install:
	${ECHO_MSG} -n ">> Installing scripts..."
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${ECHO_MSG} " [ DONE ]"

.for d in configuration dataminer dropins dvt equinox \
    external ide javavm jdbc jdev jlib jviews modules \
    netbeans ords rdbms sleepycat sqldeveloper sqlj svnkit
	${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	cd ${WRKSRC} && ${FIND} ${d} -type d \
		-exec ${MKDIR} ${STAGEDIR}/${DATADIR}/\{} \;
	cd ${WRKSRC} && ${FIND} ${d} -type f \
		-not -name "*.orig" \
		-not -name "*.exe" \
		-not -name "*.bat" \
		-not -name "*.bak" \
		-not -name "*.dll" \
		-not -name "*.so" \
		-not -name "*.jnilib" \
		-exec ${INSTALL_DATA} \{} ${STAGEDIR}/${DATADIR}/\{} \;
	${ECHO_MSG} " [ DONE ]"
.endfor

	${ECHO_MSG} -n ">> Installing icon ..."
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}/${DATADIR}/icon.png
	${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
