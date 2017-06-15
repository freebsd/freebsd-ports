# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	javahelp
PORTVERSION=	2.0.05
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/javadesktop/javahelp/
DISTNAME=	${PORTNAME}2_0_05

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Online help support for Java applications

USES=		zip
USE_JAVA=	yes
JAVA_RUN=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/jh2.0

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|$$JAVAHELP_HOME/javahelp/bin/|${JAVAJARDIR}/|' ${WRKSRC}/javahelp/bin/jhindexer
	${REINPLACE_CMD} -e 's|$$JAVAHELP_HOME/javahelp/bin/|${JAVAJARDIR}/|' ${WRKSRC}/javahelp/bin/jhsearch
	(cd ${WRKSRC} && ${RM} -r `${FIND} . -type d -name .svn`)

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.html ${STAGEDIR}${JAVAJARDIR}/LICENSE.${PORTNAME}.html
	${INSTALL_SCRIPT} ${WRKSRC}/javahelp/bin/jhindexer ${STAGEDIR}${PREFIX}/bin/jhindexer
	${INSTALL_SCRIPT} ${WRKSRC}/javahelp/bin/jhsearch ${STAGEDIR}${PREFIX}/bin/jhsearch
	${INSTALL_DATA} ${WRKSRC}/javahelp/bin/jhindexer.jar ${STAGEDIR}${JAVAJARDIR}/jhindexer.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/bin/jhsearch.jar ${STAGEDIR}${JAVAJARDIR}/jhsearch.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jh.jar ${STAGEDIR}${JAVAJARDIR}/jh.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jhall.jar ${STAGEDIR}${JAVAJARDIR}/jhall.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jhbasic.jar ${STAGEDIR}${JAVAJARDIR}/jhbasic.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jsearch.jar ${STAGEDIR}${JAVAJARDIR}/jsearch.jar
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/favorites_2_0.dtd ${STAGEDIR}${JAVAJARDIR}/dtd/favorites_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/helpset_2_0.dtd ${STAGEDIR}${JAVAJARDIR}/dtd/helpset_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/index_2_0.dtd ${STAGEDIR}${JAVAJARDIR}/dtd/index_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/map_2_0.dtd ${STAGEDIR}${JAVAJARDIR}/dtd/map_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/toc_2_0.dtd ${STAGEDIR}${JAVAJARDIR}/dtd/toc_2_0.dtd
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/demos/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
