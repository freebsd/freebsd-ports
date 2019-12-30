# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	commons-dbcp
PORTVERSION=	2.7.0
CATEGORIES=	java databases
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}2-${PORTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Apache Commons Database Connection Pool

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVALIBDIR}/commons-pool.jar:java/apache-commons-pool

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
JAVA_VERSION=	8
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}2-${PORTVERSION}
JARFILE=	${PORTNAME}2-${PORTVERSION}.jar
DOCFILES=	LICENSE.txt \
		NOTICE.txt \
		README.txt \
		RELEASE-NOTES.txt

PORTDOCS=	*
PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar \
		${JAVAJARDIR}/${JARFILE}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${LN} -sf ${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCFILES}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
