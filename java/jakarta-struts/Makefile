# New ports collection makefile for:    Struts framework
# Date created:		Thu Jun 26 15:50:28 EEST 2003
# Whom:			Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	jakarta-struts
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://www.apache.org/dist/jakarta/struts/binaries/ \
		http://apache.dnepr.net/jakarta/struts/binaries/
DIST_SUBDIR=	jakarta

MAINTAINER=	toha@toha.org.ua
COMMENT=	Struts framework

USE_JAVA=	1.3+
NO_BUILD=	YES

JAVASHAREDIR=	share/java
TDIR=		${JAVASHAREDIR}/${PKGNAME}
PLIST_SUB+=	T=${TDIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL} -d ${PREFIX}/${TDIR}/'{}' \; && \
	${FIND} . -type f -exec ${INSTALL_DATA} '{}' ${PREFIX}/${TDIR}/'{}' \;

.include <bsd.port.mk>
