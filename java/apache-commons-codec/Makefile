# $FreeBSD$

PORTNAME=	commons-codec
PORTVERSION=	1.13
CATEGORIES=	java converters
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Implementations of common encoders and decoders

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
JAVA_VERSION=	8+
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} apidocs \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES.txt \
		${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"

.include <bsd.port.mk>
