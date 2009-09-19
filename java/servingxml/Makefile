# New ports collection makefile for:   servingxml
# Date created:        6 September 2009
# Whom:                jpbeconne
#
# $FreeBSD$
#

PORTNAME=	servingxml
PORTVERSION=	1.1.1
CATEGORIES=	java devel
MASTER_SITES=	SF

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Framework for flat/XML data transformations

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
BUILD_DEPENDS+=	${ANT_CMD}:${PORTSDIR}/devel/apache-ant
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=	${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
ANT_TARGETS=	dist
JAVA_BUILD=	yes
FETCH_ARGS=	-pRr

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGETS}

do-install:
	${MKDIR} ${JAVASHAREDIR}/${PORTNAME}
	(cd ${WRKSRC}/target/${PORTNAME} && ${COPYTREE_SHARE} \* ${JAVASHAREDIR}/${PORTNAME})
	${CHMOD} 555 ${JAVASHAREDIR}/${PORTNAME}
	${CHMOD} 555 ${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}
post-install:
	${CAT} pkg-message
.include <bsd.port.mk>
