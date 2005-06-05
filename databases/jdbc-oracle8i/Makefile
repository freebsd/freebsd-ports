# New ports collection makefile for:	The Oracle 8.1.6 JDBC Drivers
# Date created:		2 January 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	oracle8i
PORTVERSION=	8.1.7.1
CATEGORIES=	databases java
MASTER_SITES=	# none
PKGNAMEPREFIX=	jdbc-
DISTFILES=	${CLASSES}${EXTRACT_SUFX} ${PATCH_FILE}${EXTRACT_SUFX}	\
		${NLS_CHARSET}${EXTRACT_SUFX}
DIST_SUBDIR=	oracle
EXTRACT_ONLY=	${CLASSES}${EXTRACT_SUFX} ${PATCH_FILE}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.Org
COMMENT=	The JDBC drivers for Oracle 8i

PATCH_DEPENDS=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip

RESTRICTED=	'Must be downloaded direct from Oracle via www interface'
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+	# Should be "1.2 1.3" but tested OK with 1.4

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

JDKVER=		12
CLASSES=	classes${JDKVER}
PATCH_FILE=	1725012_${JDKVER}
NLS_CHARSET=	nls_charset${JDKVER}

PLIST_FILES=	%%JAVAJARDIR%%/${CLASSES}${EXTRACT_SUFX}	\
		%%JAVAJARDIR%%/${NLS_CHARSET}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

.if !exists(${CLASSES:S|^|${_DISTDIR}/|}${EXTRACT_SUFX})	\
 && !exists(${PATCH_FILE:S|^|${_DISTDIR}/|}${EXTRACT_SUFX})	\
 && !exists(${NLS_CHARSET:S|^|${_DISTDIR}/|}${EXTRACT_SUFX})
IGNORE="Please manually download ${DISTFILES} from http://www.oracle.com/technology/software/tech/java/sqlj_jdbc/index.html Oracle8i 8.1.7 JDBC Drivers for use with JDK 1.2 \(JDBC classes + Oracle8i ${PORTVERSION} Patch + nls_charset12.zip\). Put ${DISTFILES} into the directory ${_DISTDIR} and run make again."
.endif

pre-patch:
	@${MV} ${WRKDIR}/v8TTIoac.class ${WRKDIR}/oracle/jdbc/ttc7/v8TTIoac.class
	@(cd ${WRKDIR}; ${LOCALBASE}/bin/zip -rq ${WRKDIR}/${CLASSES}${EXTRACT_SUFX}	\
		javax oracle)

do-install:
	${INSTALL_DATA} ${WRKDIR}/${CLASSES}${EXTRACT_SUFX} ${JAVAJARDIR}
	${INSTALL_DATA} ${_DISTDIR}/${NLS_CHARSET}${EXTRACT_SUFX} ${JAVAJARDIR}

.include <bsd.port.post.mk>
