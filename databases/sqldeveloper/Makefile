# New ports collection makefile for:	sqldeveloper
# Date created:				16 January 2008
# Whom:					jjuanino@gmail.com
#
# $FreeBSD$
#

PORTNAME=	sqldeveloper
PORTVERSION=	2.1.1.64.45
DISTVERSIONSUFFIX=-no-jre
CATEGORIES=	databases java
MASTER_SITES=	#http://www.oracle.com/technology/software/products/sql/index.html
DISTNAME=	${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}
DIST_SUBDIR=	oracle

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Graphical tool for database development

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_ZIP=	yes
USE_JAVA=	yes

JAVA_VERSION=	1.6+

NO_BUILD=	yes

RESTRICTED=	Packaging prohibited by Oracle license

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=		${PRINTF} %b

IGNORE+=		\n\n-=< MARKED AS IGNORED: >=-\n
IGNORE+=		\n
IGNORE+=		Due to Oracle license restrictions, you must fetch the source \n
IGNORE+=		distribution manually.	Please access  \n
IGNORE+=		http://www.oracle.com/technology/software/products/sql/index.html \n
IGNORE+=		with a web browser and follow the link for the \n
IGNORE+=		\"${DISTFILES}\".  \n
IGNORE+=		You will be required to register and log in, \n
IGNORE+=		but you can create an account on that page.  \n
IGNORE+=		After registration and accepting the Oracle License, \n
IGNORE+=		download the distribution file, \n ${DISTFILES}, \n
IGNORE+=		into ${DISTDIR}/${DIST_SUBDIR}/ \n
IGNORE+=		and then restart this installation\n\n
.endif

do-install:
	@${REINPLACE_CMD} -e 's|%DATADIR%|${DATADIR}|' \
			  -e 's|%JAVA_HOME%|${JAVA_HOME}|' \
	    ${WRKSRC}/sqldeveloper.sh
	@${REINPLACE_CMD} -e 's|^#!/bin/bash$$|#!${LOCALBASE}/bin/bash|' \
	    ${WRKSRC}/sqldeveloper.sh \
	    ${WRKSRC}/ide/bin/launcher.sh \
	    ${WRKSRC}/ide/bin/product-launcher.template \
	    ${WRKSRC}/sqldeveloper/bin/sqldeveloper
	@${ECHO_MSG} -n ">> Installing scripts..."
	@${INSTALL_SCRIPT} ${WRKSRC}/sqldeveloper.sh ${PREFIX}/bin/sqldeveloper
	@${ECHO_MSG} " [ DONE ]"

.for d in ide j2ee jdbc jdev jlib lib modules rdbms sleepycat sqldeveloper timingframework
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

	@${ECHO_MSG} -n ">> Installing icon ..."
	@${INSTALL_DATA} ${WRKSRC}/icon.png ${DATADIR}/icon.png
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
