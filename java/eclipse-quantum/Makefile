# New ports collection makefile for:	eclipse-quantum
# Date created:				July 30, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	quantum
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	quantum
PKGNAMEPREFIX=	eclipse-
DISTNAME=	quantum${PORTVERSION}_e3.0
DIST_SUBDIR=	eclipse

MAINTAINER=	java@freebsd.org
COMMENT=	Database access and SQL editor for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse

.include <bsd.port.mk>
