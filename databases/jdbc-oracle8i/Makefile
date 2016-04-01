# Created by: Patrick Gardella <patrick@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oracle8i
PORTVERSION=	8.1.7.1
PORTREVISION=	2
CATEGORIES=	databases java
MASTER_SITES=	# none
PKGNAMEPREFIX=	jdbc-
DISTFILES=	${CLASSES}${EXTRACT_SUFX} ${PATCH_FILE}${EXTRACT_SUFX}	\
		${NLS_CHARSET}${EXTRACT_SUFX}
DIST_SUBDIR=	oracle
EXTRACT_ONLY=	${CLASSES}${EXTRACT_SUFX} ${PATCH_FILE}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The JDBC drivers for Oracle 8i

PATCH_DEPENDS=	${LOCALBASE}/bin/zip:archivers/zip

RESTRICTED=	Must be downloaded direct from Oracle via www interface

USES=		zip
SE_JAVA=	yes
JAVA_VERSION=	1.6+

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
IGNORE=	Please manually download ${DISTFILES} from http://www.oracle.com/technology/software/tech/java/sqlj_jdbc/index.html Oracle8i 8.1.7 JDBC Drivers for use with JDK 1.2 \(JDBC classes + Oracle8i ${PORTVERSION} Patch + nls_charset12.zip\). Put ${DISTFILES} into the directory ${_DISTDIR} and run make again.
.endif

pre-patch:
	@${MV} ${WRKDIR}/v8TTIoac.class ${WRKDIR}/oracle/jdbc/ttc7/v8TTIoac.class
	@(cd ${WRKDIR}; ${LOCALBASE}/bin/zip -rq ${WRKDIR}/${CLASSES}${EXTRACT_SUFX}	\
		javax oracle)

do-install:
	${INSTALL_DATA} ${WRKDIR}/${CLASSES}${EXTRACT_SUFX} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${_DISTDIR}/${NLS_CHARSET}${EXTRACT_SUFX} ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.post.mk>
