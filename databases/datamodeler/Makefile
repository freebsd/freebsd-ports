# Created by: jjuanino@gmail.com
# $FreeBSD$

PORTNAME=	datamodeler
PORTVERSION=	3.1.0.700
DISTVERSIONSUFFIX=-1
CATEGORIES=	databases java
MASTER_SITES=	#http://www.oracle.com/technetwork/developer-tools/datamodeler/downloads/index.html
DISTNAME=	${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}.noarch
EXTRACT_SUFX=	.rpm
DIST_SUBDIR=	oracle

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Database modeling tool

EXTRACT_DEPENDS=rpm:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_JAVA=	yes

JAVA_VERSION=	1.6+

NO_BUILD=	yes

RESTRICTED=	Packaging prohibited by Oracle license
NO_CDROM=	Packaging prohibited by Oracle license

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/opt/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	readme.html
.endif

.if ${OSVERSION} < 802514
IGNORE=		tarball will not extract
.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
DISTFILE_INSTRUCTIONS	=	\n
DISTFILE_INSTRUCTIONS 	+=	Due to Oracle license restrictions, you must fetch the source \n
DISTFILE_INSTRUCTIONS 	+=	distribution manually.	Please access  \n
DISTFILE_INSTRUCTIONS 	+=	http://www.oracle.com/technetwork/developer-tools/datamodeler/downloads/index.html \n
DISTFILE_INSTRUCTIONS 	+=	with a web browser and follow the link for the \n
DISTFILE_INSTRUCTIONS 	+=	\"${DISTFILES}\".  \n
DISTFILE_INSTRUCTIONS 	+=	You will be required to register and log in, \n
DISTFILE_INSTRUCTIONS 	+=	but you can create an account on that page.  \n
DISTFILE_INSTRUCTIONS 	+=	After registration and accepting the Oracle License, \n
DISTFILE_INSTRUCTIONS 	+=	download the distribution file, \n ${DISTFILES}, \n
DISTFILE_INSTRUCTIONS 	+=	into ${DISTDIR}/${DIST_SUBDIR}/ \n
DISTFILE_INSTRUCTIONS 	+=	and then restart this installation\n\n
.endif

.if defined(DISTFILE_INSTRUCTIONS)
.if defined(PACKAGE_BUILDING)
IGNORE=		requires manual fetch
.else
pre-fetch:
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif
.endif

SUB_FILES=	${PORTNAME}.script.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

do-install:
	@${ECHO_MSG} -n ">> Installing scripts..."
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.script.sh ${PREFIX}/bin/${PORTNAME}
	@${ECHO_MSG} " [ DONE ]"

.for d in datamodeler ide jdbc jdev jlib modules rdbms sleepycat \
    sqldeveloper timingframework
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

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTNAME}/readme.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
