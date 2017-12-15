# Created by: Otacilio de Araujo Ramos Neto <otacilio.neto@bsd.com.br>
# $FreeBSD$

PORTNAME=	flexdock
PORTVERSION=	1.2.4
CATEGORIES=	devel java
MASTER_SITES=	http://forge.scilab.org/index.php/p/${PORTNAME}/downloads/get/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Swing windowing and docking framework

BROKEN_armv6=		fails to package: flexdock/api: No such file or directory
BROKEN_armv7=		fails to package: flexdock/api: No such file or directory

USE_ANT=	yes
USE_JAVA=	yes

ALL_TARGET=	dist

PLIST_FILES=	${JAVAJARDIR:C^${PREFIX}/^^}/${PORTNAME}.jar
PORTDOCS=	"User Guide.pdf" api

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA}	${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
