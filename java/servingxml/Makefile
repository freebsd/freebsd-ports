# Created by: jpbeconne
# $FreeBSD$

PORTNAME=	servingxml
PORTVERSION=	1.1.2
CATEGORIES=	java devel
MASTER_SITES=	SF

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Framework for flat/XML data transformations

BUILD_DEPENDS=	${ANT_CMD}:devel/apache-ant

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=	${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
ANT_TARGETS=	dist
JAVA_BUILD=	yes

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGETS}

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	(cd ${WRKSRC}/target/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME})
	${CHMOD} 555 ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${CHMOD} 555 ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}

.include <bsd.port.mk>
