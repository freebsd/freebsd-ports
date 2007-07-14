# New ports collection makefile for:	qdbm-java
# Date created:		September 25th, 2006
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-java

COMMENT=	Java API for QDBM

SLAVEPORT=	java

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
MASTERDIR=	${.CURDIR}/../../databases/qdbm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/java
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"
