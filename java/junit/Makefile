# Created by: OKAZAKI Tetsurou
# $FreeBSD$

PORTNAME=	junit
PORTVERSION=	4.11
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	GHL
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Regression testing utility for use with the Java(TM) Language

USE_GITHUB=	yes
GH_ACCOUNT=	junit-team
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	r${PORTVERSION}
GH_COMMIT=	c62e2df

USES=		perl5
USE_JAVA=	yes
USE_ANT=	yes

PORTDOCS=	README.html cpl-v10.html doc javadoc
PORTEXAMPLES=	*
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_FILES=	%%JAVAJARDIR%%/junit.jar \
		%%JAVAJARDIR%%/junit4.jar \
		%%DATADIR%%/src.jar

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/junit${PORTVERSION}-SNAPSHOT/junit-${PORTVERSION}-SNAPSHOT.jar \
		 ${STAGEDIR}${JAVAJARDIR}/junit.jar
	${LN} -sf junit.jar ${STAGEDIR}${JAVAJARDIR}/junit4.jar
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/junit${PORTVERSION}-SNAPSHOT/junit-${PORTVERSION}-SNAPSHOT-src.jar \
		${STAGEDIR}${DATADIR}/src.jar
	cd ${INSTALL_WRKSRC}/junit${PORTVERSION}-SNAPSHOT/junit/samples \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/
	cd ${INSTALL_WRKSRC} \
		&& ${FIND} ${PORTDOCS:Njavadoc} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \
		&& ${FIND} ${PORTDOCS:Njavadoc} -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;
	cd ${INSTALL_WRKSRC}/junit${PORTVERSION}-SNAPSHOT \
		&& ${FIND} javadoc -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \

.include <bsd.port.mk>
