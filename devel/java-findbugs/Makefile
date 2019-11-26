# Created by: glewis
# $FreeBSD$

PORTNAME=	findbugs
PORTVERSION=	1.3.9
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	SF
PKGNAMEPREFIX=	java-

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Find Bugs in Java Programs

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

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*

PORTEXAMPLES=	*

do-install:
	@-${MKDIR} ${STAGEDIR}${DATADIR}/lib
.for f in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${STAGEDIR}${DATADIR}/lib/
.endfor
	@-${MKDIR} ${STAGEDIR}${DATADIR}/bin
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
		-e "s:%%JAVAJARDIR%%:${JAVAJARDIR}:" ${WRKSRC}/bin/${PORTNAME}2
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}2 ${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	${LN} -sf ${DATADIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@-${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in LICENSE* README*
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	@-${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
