# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>

PORTNAME=	commons-discovery
PORTVERSION=	0.5
CATEGORIES=	java devel
MASTER_SITES=	https://archive.apache.org/dist/commons/discovery/binaries/
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Java library for locating resources (including classes)

LICENSE=	APACHE20

DEPRECATED=	Abandoned upstream, last release in 2006
EXPIRATION_DATE=2022-03-31

USE_JAVA=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*
JARFILE=	${PORTNAME}.jar
PLIST_FILES+=	${JAVAJARDIR}/${JARFILE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${JARFILE}
	cd ${WRKSRC}/apidocs && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC}/apidocs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;

.include <bsd.port.mk>
