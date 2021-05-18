# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>

PORTNAME=	trove4j
PORTVERSION=	3.1a1
CATEGORIES=	java devel
MASTER_SITES=	https://bitbucket.org/${PORTNAME}/trove/downloads/
DISTNAME=	trove-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance collections API for Java

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
NO_BUILD=	yes

PORTDOCS=	javadocs AUTHORS.txt CHANGES.txt LICENSE.txt README-idea-devel.txt \
		README-license.txt README.txt
JARFILE=	trove-${PORTVERSION}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}
WRKSRC=		${WRKDIR}/${PORTVERSION}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
