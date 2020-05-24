# Created by: Conor McDermottroe <ports@mcdermottroe.com>
# $FreeBSD$

PORTNAME=	jflex
PORTVERSION=	1.8.1
CATEGORIES=	java devel
MASTER_SITES=	https://github.com/jflex-de/jflex/releases/download/v${PORTVERSION}/

MAINTAINER=	eg@fbsd.lt
COMMENT=	Fast Lexical Analyser Generator for Java[tm]

LICENSE=	BSD3CLAUSE

USE_JAVA=	yes

#
# JFlex has two build options --- Maven and Bazel --- and neither of
# them are easy within the Ports tree framework.  If you *really* want
# to build it from source, grab the distfile (which includes the source)
# or the entire repo, and have fun!     -- ~jashankj, 2020-04-08
#
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
SUB_FILES=	jflex.sh
SUB_LIST+=	PORTVERSION=${PORTVERSION}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jflex.sh ${STAGEDIR}${PREFIX}/bin/jflex
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-full-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar
	${LN} -s ${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name \.* ")

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name \.*")

.include <bsd.port.mk>
