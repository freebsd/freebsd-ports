# Created by: jjuanino@gmail.com
# $FreeBSD$

PORTNAME=	sqldeveloper
PORTVERSION=	3.2.20.09.87
DISTVERSIONSUFFIX=-no-jre
CATEGORIES=	databases java
MASTER_SITES=	#http://www.oracle.com/technology/software/products/sql/index.html
DIST_SUBDIR=	oracle

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Graphical tool for database development

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_ZIP=	yes
USE_JAVA=	yes

JAVA_VERSION=	1.6+

NO_BUILD=	yes

RESTRICTED=	Packaging prohibited by Oracle license
NO_CDROM=	Packaging prohibited by Oracle license

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} PORTNAME=${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	readme.html
.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	Due to Oracle license restrictions, you must fetch the source \
distribution manually. Please access \
http://www.oracle.com/technology/software/products/sql/index.html \
with a web browser and follow the link for the ${DISTFILES}. You will be \
required to register and log in, but you can create an account on that \
page. After registration and accepting the Oracle License, download the \
distribution file, ${DISTFILES}, into ${DISTDIR}/${DIST_SUBDIR}/ and then \
restart this installation
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing scripts..."
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${ECHO_MSG} " [ DONE ]"

.for d in dataminer jdbc jviews sleepycat timingframework \
    ide jdev modules sqldeveloper javavm jlib rdbms sqlj
	@${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	@cd ${WRKSRC} && ${FIND} ${d} -type d \
		-not -path "jdev/extensions/oracle.jdeveloper.subversion/licenses" \
		-exec ${MKDIR} ${DATADIR}/\{} \;
	@cd ${WRKSRC} && ${FIND} ${d} -type f \
		-not -name "*.orig" \
		-not -name "*.exe" \
		-not -name "*.bat" \
		-not -name "*.bak" \
		-not -name "*.dll" \
		-not -path "jdev/extensions/oracle.jdeveloper.subversion/licenses/*" \
		-exec ${INSTALL_DATA} \{} ${DATADIR}/\{} \;
	@${ECHO_MSG} " [ DONE ]"
.endfor

.for f in jdev.label view-source-paths.lis
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/${f}
.endfor

	@${ECHO_MSG} -n ">> Installing icon ..."
	@${INSTALL_DATA} ${WRKSRC}/icon.png ${DATADIR}/icon.png
	@${ECHO_MSG} " [ DONE ]"

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} readme.html ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
