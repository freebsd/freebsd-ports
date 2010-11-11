# New ports collection makefile for:	Jakarta Commons DBCP
# Date created:				October 6, 2003
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	commons-dbcp
PORTVERSION=	1.4
CATEGORIES=	java databases
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	The DBCP Component

BUILD_DEPENDS=	${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool \
		${JAVALIBDIR}/jta.jar:${PORTSDIR}/java/jta
RUN_DEPENDS=	${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool \
		${JAVALIBDIR}/jta.jar:${PORTSDIR}/java/jta

USE_JAVA=	yes
JAVA_VERSION=	1.4+

USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
ALL_TARGET=	build-jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
