# Ports collection makefile for:	j2sdkee13
# Date created:				2003-06-27
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	j2sdkee
PORTVERSION=	1.3.1
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	# http://java.sun.com/j2ee/sdk_1.3/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-linux

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java 2 SDK Enterprise Edition

USE_JAVA=	yes
JAVA_VERSION=	1.3+

NO_BUILD=	YES

RESTRICTED=	"Redistribution is not permitted"
NO_CDROM=	"Redistribution is not permitted"

J2SDKEEVERSION=	${PORTVERSION}_02
DOWNLOAD_URL?=	http://javashoplm.sun.com/ECom/docs/Welcome.jsp?StoreId=22&PartDetailId=7917-j2ee_sdk-1.3.1-oth-JPR&SiteId=JSC&TransactionId=noreg

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		You must manually fetch the Java 2 SDK Enterprise Edition\
		${J2SDKEEVERSION} tarball from ${DOWNLOAD_URL}.  Accept the\
		license and then download ${DISTNAME}${EXTRACT_SUFX} into\
		${DISTDIR} and run ${MAKE} again
.endif

do-install:
	(cd ${WRKDIR} && ${TAR} cf - ${PORTNAME}${PORTVERSION} |\
		${TAR} xf - -C ${PREFIX})

.include <bsd.port.post.mk>
