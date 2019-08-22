# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	netty
PORTVERSION=	4.1.39
DISTVERSIONSUFFIX=	.Final
CATEGORIES=	java devel
MASTER_SITES=	http://dl.bintray.com/netty/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java NIO client server framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe tar:bzip2
USE_JAVA=	yes

CPE_VENDOR=	netty_project
JAVA_VERSION=	8+
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.Final

DOCDIRS=	javadoc \
		license
DOCFILES=	CONTRIBUTING.md \
		LICENSE.txt \
		NOTICE.txt \
		README.md

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/jar/all-in-one/${PORTNAME}-all-${PORTVERSION}.Final.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar
	${LN} -nfs ${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.for DIR in ${DOCDIRS}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ${DOCFILES}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
