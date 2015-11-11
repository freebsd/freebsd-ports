# Created by: Quinton Dolan <q@onthenet.com.au>
# $FreeBSD$

PORTNAME=	openbase
PORTVERSION=	2006.10
CATEGORIES=	databases java
MASTER_SITES+=	http://web.mac.com/openbase/download/interfaces/
PKGNAMESUFFIX=	-jdbc
DISTNAME=	OpenBaseJDBC_${OBVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	The Java JDBC implementation for OpenBase

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
JARFILE=	OpenBaseJDBC.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OBVERSION=	Oct2006
WORK_SUBDIR=	JDBC_10.09.2006

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${WORK_SUBDIR}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${JARFILE}

.include <bsd.port.post.mk>
