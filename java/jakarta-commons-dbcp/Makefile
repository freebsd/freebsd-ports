# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	commons-dbcp
PORTVERSION=	1.4
CATEGORIES=	java databases
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	The DBCP Component

LICENSE=	APACHE20

BUILD_DEPENDS=	${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool \
		${JAVALIBDIR}/jta.jar:${PORTSDIR}/java/jta
RUN_DEPENDS=	${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool \
		${JAVALIBDIR}/jta.jar:${PORTSDIR}/java/jta

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
JAVA_VERSION=	1.6

USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
ALL_TARGET=	build-jar

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO} " [ DONE ]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
