# New ports collection makefile for:	Jakarta Commons Lang
# Date created:				October 18, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-lang
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-commons/release/${PORTNAME}/v${PORTVERSION}/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/jakarta-ant

USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/${DISTNAME}/lang
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	jar javadoc
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}-${PORTVERSION}.jar
DESTJARFILE=	${PORTNAME}.jar

post-patch:
	@${CP} ${WRKSRC}/LICENSE.txt ${WRKSRC}/../LICENSE

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${DESTJARFILE}.jar..."
	@${CP} ${WRKSRC}/dist/${JARFILE} ${JARDIR}/${DESTJARFILE}
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/dist/docs/api/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
