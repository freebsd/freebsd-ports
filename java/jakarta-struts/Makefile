# New ports collection makefile for:    Struts framework
# Date created:		Thu Jun 26 15:50:28 EEST 2003
# Whom:			Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	jakarta-struts
PORTVERSION=	1.2.4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=struts/binaries
DIST_SUBDIR=	jakarta

MAINTAINER=	toha@toha.org.ua
COMMENT=	Struts framework

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	YES
USE_ZIP=	YES

JAVASHAREDIR=	share/java
TDIR=		${JAVASHAREDIR}/${PKGNAME}
PLIST_SUB+=	T=${TDIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL} -d ${PREFIX}/${TDIR}/'{}' \; && \
	${FIND} . -type f -exec ${INSTALL_DATA} '{}' ${PREFIX}/${TDIR}/'{}' \;

.include <bsd.port.mk>
