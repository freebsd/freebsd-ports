# New ports collection makefile for:	jdk-doc-1.2
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	${JDK_VERSION:S/_/./g}
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	jdk-${JDK_VERSION:S/./_/g}-doc

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VER} Documentation

LATEST_LINK=	jdk${JDK_CONCAT_VER}-doc
DOCSDIR?=	${PREFIX}/share/doc/jdk${JDK_MAJOR_VER}
NO_CDROM=	"License does not allow distribution with fee."
RESTRICTED=	"This documentation is under license and export control."

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION:C/_.*\$//g}/docs
JDK_VERSION=	1.2.2_006
JDK_MAJOR_VER=	${JDK_VERSION:R}
JDK_CONCAT_VER=	${JDK_MAJOR_VER:S/.//g}

NO_BUILD=	yes
PORTDOCS=	api guide images index.html relnotes tooldocs

.include <bsd.port.pre.mk>

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
