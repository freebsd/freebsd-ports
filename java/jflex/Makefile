# Ports collection Makefile for:	JFlex
# Date created:				27 January 2004
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	jflex
PORTVERSION=	1.3.5
CATEGORIES=	java devel
MASTER_SITES=	http://www.jflex.de/

MAINTAINER=	ports@mcdermottroe.com
COMMENT=	The Fast Lexical Analyser Generator for Java[tm]

USE_JAVA=	1.1+
NEED_JAVAC=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/JFlex
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ENV+=	JAVAC="${JAVAC}" JAR="${JAR}" JAVAJARDIR="${JAVAJARDIR}" \
		JAVA_CLASSES="${JAVA_CLASSES}"

PLIST_SUB=	JAVAJARDIR=${JAVAJARDIR:S|^${PREFIX}/||}
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-configure:
	@${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|' \
		${WRKSRC}/bin/jflex

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/jflex ${PREFIX}/bin/jflex
	@${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar ${JAVAJARDIR}/JFlex.jar
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
