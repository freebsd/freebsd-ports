# New ports collection makefile for:   bugseeker
# Date created:        22 December 2000
# Whom:                Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugseeker
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	bugseeker2ee-1_0_2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BugSeeker for Java 2, a debugger for Java applications

USE_JAVA=	1.3+

NO_CDROM=	"License doesn\'t allow redistribution"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/bugseeker2
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR=	${PREFIX}/${PKGBASE}${PORTVERSION}
DOWNLOAD_URL?=	http://www.karmira.com/store/index.html

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually obtain the ${DISTNAME}${EXTRACT_SUFX} file from Karmira, at ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	${CAT} ${WRKSRC}/bin/bugseeker2.sh \
	| ${SED} "/%%TARGET_DIR%%/s//${TARGET_DIR:S/\//\\\//g}/" \
	| ${SED} "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	> ${WRKSRC}/bin/bugseeker
	${CHMOD} a+xr ${WRKSRC}/bin/bugseeker
	${MKDIR} ${TARGET_DIR}
	${CP} ${WRKSRC}/changes.txt ${TARGET_DIR}/
	${CP} ${WRKSRC}/license.txt ${TARGET_DIR}/
	${CP} ${WRKSRC}/readme.txt ${TARGET_DIR}/
	${CP} ${WRKSRC}/bin/bugseeker ${PREFIX}/bin
	${MKDIR} ${TARGET_DIR}/lib
	${CP} -r ${WRKSRC}/lib/* ${TARGET_DIR}/lib/
	${MKDIR} ${TARGET_DIR}/manual
	${CP} -r ${WRKSRC}/manual/* ${TARGET_DIR}/manual/

.include <bsd.port.post.mk>
