# New ports collection makefile for:	Jakarta Commons Pool
# Date created:				October 6, 2003
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	commons-pool
PORTVERSION=	1.0.1
CATEGORIES=	java
MASTER_SITES=	http://www.apache.org/dist/jakarta/commons/pool/source/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	pool-${PORTVERSION}-src
DIST_SUBDIR=	jakarta

MAINTAINER=	toha@toha.org.ua
COMMENT=	Jakarta Object-pooling API

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/commons-${DISTNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	dist-jar
.else
ANT_TARGET=	dist-jar doc
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}.jar
DESTJARFILE=	${PORTNAME}.jar

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

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
