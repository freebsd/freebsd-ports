# New ports collection makefile for:   hsqldb
# Date created:        14 Feb 2006
# Whom:                Michael Winking <mwfp@foldl.net>
#
# $FreeBSD$
#

PORTNAME=	hsqldb
PORTVERSION=	1.8.0.2
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hsqldb
DISTNAME=	hsqldb_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.zip

MAINTAINER=	mwfp@foldl.net
COMMENT=	An embeddable SQL database written in Java

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/build
ALL_TARGET=	hsqldb hsqljdbc
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar %%JAVAJARDIR%%/hsqljdbc.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	hsqlFindFile.html hsqldb_lic.txt hypersonic_lic.txt guide images
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files to ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/lib/hsqldb.jar \
		${JAVAJARDIR}/hsqldb.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/hsqljdbc.jar \
		${JAVAJARDIR}/hsqljdbc.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} guide images \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/doc/hsqlFindFile.html \
		${WRKSRC}/doc/hsqldb_lic.txt \
		${WRKSRC}/doc/hypersonic_lic.txt \
		${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
