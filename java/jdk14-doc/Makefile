# New ports collection makefile for:	jdk-doc-1.4
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	${JDK_VERSION:S/_/./g}
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	j2sdk-${JDK_VERSION:S/./_/g}-doc

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VER} Documentation

LATEST_LINK=	jdk${JDK_CONCAT_VER}-doc
DOCSDIR?=	${PREFIX}/share/doc/jdk${JDK_MAJOR_VER}
NO_CDROM=	"License does not allow distribution with fee."
RESTRICTED=	"This documentation is under license and export control."

WRKSRC=		${WRKDIR}/docs
JDK_VERSION=	1.4.2
JDK_MAJOR_VER=	${JDK_VERSION:R}
JDK_CONCAT_VER=	${JDK_MAJOR_VER:S/.//g}
SUN_BUNDLE_ID=	8602
DOWNLOAD_URL=	http://java.sun.com/webapps/download/Display?BundleId=${SUN_BUNDLE_ID}

NO_BUILD=	yes
USE_ZIP=	yes
PORTDOCS=	api guide images index.html install-notes relnotes tooldocs

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
