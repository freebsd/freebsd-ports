PORTNAME=	commons-logging
DISTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Generic logging wrapper library
WWW=		https://commons.apache.org/proper/commons-logging/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		java

EXTRACT_AFTER_ARGS=	--exclude ._* \
			--exclude .DS_Store \
			--exclude ${PORTNAME}-${DISTVERSION}-*.jar \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

JARFILE=	${PORTNAME}-${DISTVERSION}.jar

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar \
		${JAVAJARDIR}/${JARFILE}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${RLN}  ${STAGEDIR}${JAVAJARDIR}/${JARFILE} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} NOTICE.txt RELEASE-NOTES.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
