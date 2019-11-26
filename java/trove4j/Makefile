# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	trove4j
PORTVERSION=	3.1a1
CATEGORIES=	java devel
MASTER_SITES=	https://bitbucket.org/robeden/trove/downloads/
DISTNAME=	trove-${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High performance collections API for Java

BROKEN=		unfetchable

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
