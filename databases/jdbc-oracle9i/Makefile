# New ports collection makefile for:	The Oracle 8.1.6 JDBC Drivers
# Date created:		2 January 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	oracle816
PORTVERSION=	1.11
CATEGORIES=	databases java
MASTER_SITES=	# none
PKGNAMEPREFIX=	jdbc-
DISTNAME=	classes111_01.
EXTRACT_SUFX=	zip
EXTRACT_ONLY=	# none

MAINTAINER=	patrick@FreeBSD.Org
COMMENT=	The JDBC drivers for Oracle 8.1.6

RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk11

ALL_TARGET=	jar

RESTRICTED=	'Must be downloaded direct from Oracle via www interface'
NO_CDROM=	'Must be downloaded direct from Oracle via www interface'
NO_PACKAGE=	'Must be downloaded direct from Oracle via www interface'
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	share/java/classes/classes111_01.zip

.include <bsd.port.pre.mk>

.if !exists(${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="Please manually download ${DISTNAME}${EXTRACT_SUFX} from http://technet.oracle.com/software/tech/java/sqlj_jdbc/software_index.htm Oracle8i 8.1.6.0.1 JDBC Drivers for use with JDK 1.1.x, JDBC-Thin 100% Java. Put ${DISTNAME}${EXTRACT_SUFX} into the directory ${_DISTDIR} and run make again."
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${LOCALBASE}/share/java/classes

.include <bsd.port.post.mk>
