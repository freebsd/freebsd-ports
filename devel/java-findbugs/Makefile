# New ports collection makefile for:   findbugs
# Date created:        19 December 2010
# Whom:                glewis
#
# $FreeBSD$
#

PORTNAME=	findbugs
PORTVERSION=	1.3.9
CATEGORIES=	devel java
MASTER_SITES=	SF
PKGNAMEPREFIX=	java-

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Find Bugs in Java Programs

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

LICENSE=	LGPL21
USE_JAVA=	yes
NO_BUILD=	yes

JAR_FILES=	annotations.jar \
		ant.jar \
		asm-3.1.jar \
		asm-analysis-3.1.jar \
		asm-commons-3.1.jar \
		asm-tree-3.1.jar \
		asm-util-3.1.jar \
		asm-xml-3.1.jar \
		bcel.jar \
		commons-lang-2.4.jar \
		dom4j-1.6.1.jar \
		${PORTNAME}.jar \
		${PORTNAME}-ant.jar \
		jFormatString.jar \
		jaxen-1.1.1.jar \
		jdepend-2.9.jar \
		jsr305.jar \
		mysql-connector-java-5.1.7-bin.jar

.for f in ${JAR_FILES}
PLIST_FILES+=		%%DATADIR%%/lib/${f}
.endfor
PLIST_FILES+=		%%DATADIR%%/bin/${PORTNAME} \
			bin/${PORTNAME}
PLIST_DIRS+=		%%DATADIR%%/lib \
			%%DATADIR%%/bin \
			%%DATADIR%%

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

do-install:
	@-${MKDIR} ${DATADIR}/lib
.for f in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${DATADIR}/lib/
.endfor
	@-${MKDIR} ${DATADIR}/bin
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
		-e "s:%%JAVAJARDIR%%:${JAVAJARDIR}:" ${WRKSRC}/bin/${PORTNAME}2
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}2 ${DATADIR}/bin/${PORTNAME}
	${LN} -sf ${DATADIR}/bin/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@-${MKDIR} ${DOCSDIR}
.for f in LICENSE* README*
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@-${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
	@cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
