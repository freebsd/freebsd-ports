# New ports collection makefile for:	JDK documentation
# Date created:		Mon Mar  8 10:10:42 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	${JDK_VERSION:S/_/./g}
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	jdk-${JDK_VERSION:S/./_/g}-doc

MAINTAINER=	znerd@FreeBSD.org

NO_CDROM=	"License does not allow distribution with fee."
RESTRICTED=	"This software is under license and export control."

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=	"You cannot legally distribute packages"
.endif

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/share/doc/jdk${JDK_MAJOR_VER}

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION:C/_.*\$//g}/docs
JDK_VERSION=	1.1.8_003
JDK_MAJOR_VER=	${JDK_VERSION:R}
DOWNLOAD_URL=	http://java.sun.com/jdk/${JDK_MAJOR_VER}/docs.html

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	${MKDIR} ${TARGET_DIR}
	${CP} -r ${WRKSRC}/* ${TARGET_DIR}

.include <bsd.port.post.mk>
