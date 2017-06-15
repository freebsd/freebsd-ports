# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	apache-rat
PORTVERSION=	0.12
CATEGORIES=	devel java
MASTER_SITES=	APACHE/creadur/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Release audit tool

LICENSE=	APACHE20

USES=		tar:bzip2
USE_JAVA=	yes

NO_BUILD=	YES
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	README-ANT.txt README-CLI.txt README.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	apache-rat.sh

.include <bsd.port.options.mk>

do-install:
	@${ECHO_MSG} ">> Installing JAR..."
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar \
	   ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} ">> Installing script..."
	${INSTALL_SCRIPT} ${WRKDIR}/apache-rat.sh ${STAGEDIR}${PREFIX}/bin/apache-rat
	@${ECHO_MSG} " [ DONE ]"

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} ">> Installing documentation..."
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
