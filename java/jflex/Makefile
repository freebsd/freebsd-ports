# Ports collection Makefile for:	JFlex
# Date created:				27 January 2004
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	jflex
PORTVERSION=	1.4.2
CATEGORIES=	java devel
MASTER_SITES=	http://www.jflex.de/:jflexde \
		http://jflex.sourceforge.net/jar/devel/:jflexsf
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:jflexde \
		JFlex.jar:jflexsf \
		java_cup.jar:jflexsf
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
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
	${INSTALL_SCRIPT} ${WRKDIR}/jflex.sh ${PREFIX}/bin/jflex
	${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar ${JAVAJARDIR}/JFlex.jar
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
.for EXAMPLE in binary byaccj cup interpreter java simple standalone
	${MKDIR} ${EXAMPLESDIR}/${EXAMPLE}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXAMPLE}/* ${EXAMPLESDIR}/${EXAMPLE}
.endfor

.include <bsd.port.mk>
