# Created by: Conor McDermottroe <ports@mcdermottroe.com>
# $FreeBSD$

PORTNAME=	jflex
PORTVERSION=	1.4.2
CATEGORIES=	java devel
MASTER_SITES=	http://www.jflex.de/:jflexde \
		http://jflex.sourceforge.net/jar/devel/:jflexsf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:jflexde \
		JFlex.jar:jflexsf \
		java_cup.jar:jflexsf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	eg@fbsd.lt
COMMENT=	The Fast Lexical Analyser Generator for Java[tm]

BROKEN=		unfetchable

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit

USE_JAVA=	yes
USE_ANT=	yes
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	jar
MAKE_ENV+=	CLASSPATH="${JAVALIBDIR}/junit.jar"

PORTDOCS=	*

SUB_FILES=	jflex.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	${MKDIR} ${WRKSRC}/tools
	${CP} ${DISTDIR}/JFlex.jar ${WRKSRC}/tools/
	${CP} ${DISTDIR}/java_cup.jar ${WRKSRC}/tools/

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jflex.sh ${STAGEDIR}${PREFIX}/bin/jflex
	${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar ${STAGEDIR}${JAVAJARDIR}/JFlex.jar
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for EXAMPLE in binary byaccj cup interpreter java simple standalone
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${EXAMPLE}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXAMPLE}/* ${STAGEDIR}${EXAMPLESDIR}/${EXAMPLE}
.endfor

.include <bsd.port.mk>
