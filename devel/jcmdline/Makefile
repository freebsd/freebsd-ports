# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	jcmdline
PORTVERSION=	2.0.0
CATEGORIES=	devel java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java command line processor

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

LICENSE=	MPL

JARFILE=	${PORTNAME}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
DOCFILES=	CHANGES CREDITS README
PORTDOCS=	*

do-install:
	${INSTALL_DATA} ${JARFILE:S|.jar|-${PORTVERSION}.jar|:S|^|${WRKSRC}/|}	\
		${STAGEDIR}${JAVAJARDIR}/${JARFILE}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
