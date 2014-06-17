# Created by: Conor McDermottroe <ports@mcdermottroe.com>
# $FreeBSD$

PORTNAME=	jflex
PORTVERSION=	1.4.2
CATEGORIES=	java devel
MASTER_SITES=	http://www.jflex.de/:jflexde \
		http://jflex.sourceforge.net/jar/devel/:jflexsf
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:jflexde \
		JFlex.jar:jflexsf \
		java_cup.jar:jflexsf
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	eg@fbsd.lt
COMMENT=	The Fast Lexical Analyser Generator for Java[tm]

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
USE_ANT=	yes
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	jar
MAKE_ENV+=	CLASSPATH="${JAVALIBDIR}/junit.jar"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

SUB_FILES=	jflex.sh

post-extract:
	${MKDIR} ${WRKSRC}/tools
	${CP} ${DISTDIR}/JFlex.jar ${WRKSRC}/tools/
	${CP} ${DISTDIR}/java_cup.jar ${WRKSRC}/tools/

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jflex.sh ${STAGEDIR}${PREFIX}/bin/jflex
	${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar ${STAGEDIR}${JAVAJARDIR}/JFlex.jar
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for EXAMPLE in binary byaccj cup interpreter java simple standalone
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${EXAMPLE}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXAMPLE}/* ${STAGEDIR}${EXAMPLESDIR}/${EXAMPLE}
.endfor

.include <bsd.port.mk>
