# New ports collection makefile for:	jdk-doc-1.4
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	${JDK_VERSION:S/_/./g:S/-beta/b1/}
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	j2sdk-${JDK_VERSION:S/./_/g}-doc

MAINTAINER=	ernst@jollem.com

NO_CDROM=	"License does not allow distribution with fee."
RESTRICTED=	"This software is under license and export control."

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=	"You cannot legally distribute packages"
.endif

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/share/doc/jdk${JDK_MAJOR_VER}

WRKSRC=		${WRKDIR}/docs
JDK_VERSION=	1.4.0-beta
JDK_MAJOR_VER=	${JDK_VERSION:R}
DOWNLOAD_URL=	http://java.sun.com/j2se/${JDK_MAJOR_VER}/\#download

NO_BUILD=	yes
USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	${MKDIR} ${TARGET_DIR}
	${CP} -r ${WRKSRC}/* ${TARGET_DIR}

.include <bsd.port.post.mk>
