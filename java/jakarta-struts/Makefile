# New ports collection makefile for:    Struts framework
# Date created:		Thu Jun 26 15:50:28 EEST 2003
# Whom:			Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	jakarta-struts
PORTVERSION=	1.1-rc2
CATEGORIES=	java
MASTER_SITES=	http://apache.dnepr.net/jakarta/struts/binaries/
DIST_SUBDIR=	jakarta

MAINTAINER=	toha@toha.org.ua
COMMENT=	Struts framework

USE_JAVA=	1.3+
NO_BUILD=	YES

JAVASHAREDIR=	${PREFIX}/share/java

do-install:
	${CP} -r ${WRKSRC}/ ${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
