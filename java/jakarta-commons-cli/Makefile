# New ports collection makefile for:	Jakarta Commons CLI
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-cli
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/cli/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	cli-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java library for command line arguments and options

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant \
		${LOCALBASE}/share/java/classes/commons-lang.jar:${PORTSDIR}/java/jakarta-commons-lang

USE_JAVA=	1.2+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar -Dnoget
.else
ANT_TARGET=	jar javadoc -Dnoget -verbose
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}-${PORTVERSION}-beta-2-dev.jar
DESTJARFILE=	${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	${WRKSRC}/target/docs/apidocs
.endif

do-build:
	@${MKDIR} ${WRKSRC}/lib
	@cd ${WRKSRC} && ${SETENV} ANT_INCLUDE_SHARED_JARS=YES ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${DESTJARFILE}..."
	@${CP} ${WRKSRC}/target/${JARFILE} ${JARDIR}/${DESTJARFILE}
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/target/docs/apidocs/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
