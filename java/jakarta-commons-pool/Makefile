# New ports collection makefile for:	Jakarta Commons Pool
# Date created:				October 6, 2003
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	commons-pool
PORTVERSION=	1.5.5
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Jakarta Object-pooling API

USE_JAVA=	yes
JAVA_VERSION=	1.4+

USE_ANT=	yes
ALL_TARGET=	build-jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
