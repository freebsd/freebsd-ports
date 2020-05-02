# Created by: Otacilio de Araujo Ramos Neto <otacilio.neto@bsd.com.br>
# $FreeBSD$

PORTNAME=	flexdock
PORTVERSION=	1.2.4
CATEGORIES=	devel java
MASTER_SITES=	http://forge.scilab.org/index.php/p/${PORTNAME}/downloads/get/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Swing windowing and docking framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_ANT=	yes
USE_JAVA=	yes

ALL_TARGET=	dist

PLIST_FILES=	${JAVAJARDIR}/flexdock.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA}	${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
