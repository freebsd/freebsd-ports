# New ports collection makefile for:    frontbase-jdbc
# Date created:                         Mon Apr 16 07:07:22 EST 2007
# Whom:                                 Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME=	frontbase
PORTVERSION=	2.5.6
CATEGORIES=	databases java
MASTER_SITES+=	http://www.frontbase.com/download/JDBC/
PKGNAMESUFFIX=	-jdbc
DISTNAME=	FrontBaseJDBC-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER?=	q@onthenet.com.au
COMMENT=	The Java JDBC implementation for FrontBase

USE_JAVA=	yes
JAVA_VERSION=	1.4+

NO_BUILD=	yes
JARFILE=	frontbasejdbc.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/${JARFILE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
