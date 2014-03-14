# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	javahelp
PORTVERSION=	2.0.05
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/javadesktop/javahelp/ \
		http://www.predatorlabs.net/dl/
DISTNAME=	${PORTNAME}2_0_05

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system to add online help to Java applications

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/jh2.0

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|$$JAVAHELP_HOME/javahelp/bin/|${JAVAJARDIR}/|' ${WRKSRC}/javahelp/bin/jhindexer
	${REINPLACE_CMD} -e 's|$$JAVAHELP_HOME/javahelp/bin/|${JAVAJARDIR}/|' ${WRKSRC}/javahelp/bin/jhsearch
	(cd ${WRKSRC} && ${RM} -rf `${FIND} . -type d -name .svn`)

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.html ${JAVAJARDIR}/LICENSE.${PORTNAME}.html
	${INSTALL_SCRIPT} ${WRKSRC}/javahelp/bin/jhindexer ${PREFIX}/bin/jhindexer
	${INSTALL_SCRIPT} ${WRKSRC}/javahelp/bin/jhsearch ${PREFIX}/bin/jhsearch
	${INSTALL_DATA} ${WRKSRC}/javahelp/bin/jhindexer.jar ${JAVAJARDIR}/jhindexer.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/bin/jhsearch.jar ${JAVAJARDIR}/jhsearch.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jh.jar ${JAVAJARDIR}/jh.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jhall.jar ${JAVAJARDIR}/jhall.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jhbasic.jar ${JAVAJARDIR}/jhbasic.jar
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/jsearch.jar ${JAVAJARDIR}/jsearch.jar
	${MKDIR} ${JAVAJARDIR}/dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/favorites_2_0.dtd ${JAVAJARDIR}/dtd/favorites_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/helpset_2_0.dtd ${JAVAJARDIR}/dtd/helpset_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/index_2_0.dtd ${JAVAJARDIR}/dtd/index_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/map_2_0.dtd ${JAVAJARDIR}/dtd/map_2_0.dtd
	${INSTALL_DATA} ${WRKSRC}/javahelp/lib/dtd/toc_2_0.dtd ${JAVAJARDIR}/dtd/toc_2_0.dtd
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
	(cd ${WRKSRC}/demos/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
