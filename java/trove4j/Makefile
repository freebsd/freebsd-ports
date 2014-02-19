# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	trove4j
PORTVERSION=	1.1b5
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/trove/trove-${PORTVERSION}
DISTNAME=	trove-${PORTVERSION}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	High performance collections API for Java

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PORTDOCS=	javadocs AUTHORS ChangeLog LICENSE.txt README-license.txt README.txt
JARFILE=	trove.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
