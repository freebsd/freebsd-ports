# New ports collection makefile for:	Jakarta Commons Pool
# Date created:				October 6, 2003
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	commons-pool
PORTVERSION=	1.2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	toha@toha.org.ua
COMMENT=	Jakarta Object-pooling API

BUILD_DEPENDS=	${JAR_DEPENDS}
RUN_DEPENDS=	${JAR_DEPENDS}

JAR_DEPENDS=	${JAVALIBDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections

USE_JAVA=	yes
JAVA_VERSION=	1.2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ANT=	yes
MAKE_ENV+=	ANT_INCLUDE_SHARED_JARS=YES
.if defined(NOPORTDOCS)
ALL_TARGET=	build-jar
.else
ALL_TARGET=	build-jar javadoc
PORTDOCS=	*
.endif
JARFILE=	${PORTNAME}.jar
DESTJARFILE=	${PORTNAME}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/dist/docs/api \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
