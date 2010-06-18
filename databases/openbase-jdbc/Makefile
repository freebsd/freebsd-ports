# New ports collection makefile for:    openbase-jdbc
# Date created:                         Mon Apr 16 07:07:22 EST 2007
# Whom:                                 Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME=	openbase
PORTVERSION=	2006.10
CATEGORIES=	databases java
MASTER_SITES+=	http://web.mac.com/openbase/download/interfaces/
PKGNAMESUFFIX=	-jdbc
DISTNAME=	OpenBaseJDBC_${OBVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	The Java JDBC implementation for OpenBase

USE_JAVA=	yes
USE_ZIP=	yes
JAVA_VERSION=	1.4+

NO_BUILD=	yes
JARFILE=	OpenBaseJDBC.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OBVERSION=	Oct2006
WORK_SUBDIR=	JDBC_10.09.2006

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${WORK_SUBDIR}/${JARFILE} ${JAVAJARDIR}/${JARFILE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
