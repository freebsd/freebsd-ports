# New ports collection makefile for:	Jakarta Commons DBCP
# Date created:				October 6, 2003
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	commons-dbcp
PORTVERSION=	1.1
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/dbcp/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DIST_SUBDIR=	jakarta

MAINTAINER=	toha@toha.org.ua
COMMENT=	The DBCP Component

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant \
		${JAVAJARDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool

USE_JAVA=	yes
JAVA_VERSION=	1.4+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	build-jar
.else
ANT_TARGET=	build-jar javadoc
PORTDOCS=	*
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	${JAVAJARDIR:S,^${PREFIX}/,,}/${DESTJARFILE}

post-patch:
	@${CP} ${WRKSRC}/LICENSE.txt ${WRKSRC}/../LICENSE

do-build:
	@cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} ANT_INCLUDE_SHARED_JARS=YES \
			${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${DESTJARFILE}..."
	@${CP} ${WRKSRC}/dist/${JARFILE} ${JARDIR}/${DESTJARFILE}
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/dist/docs/api/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
