# New ports collection makefile for:	Jakarta Commons Pool
# Date created:				October 6, 2003
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	commons-pool
PORTVERSION=	1.1
CATEGORIES=	java
MASTER_SITES=	http://www.apache.org/dist/jakarta/commons/pool/source/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DIST_SUBDIR=	jakarta

MAINTAINER=	toha@toha.org.ua
COMMENT=	Jakarta Object-pooling API

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant \
		${JAVAJARDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections

USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
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

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ANT_INCLUDE_SHARED_JARS=YES ${ANT} ${ANT_TARGET}

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
