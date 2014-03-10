# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	jakarta-struts
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=struts/binaries
DIST_SUBDIR=	jakarta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Struts framework

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	YES
USES=		zip

JAVASHAREDIR=	share/java
TDIR=		${JAVASHAREDIR}/${PKGNAME}
PLIST_SUB+=	T=${TDIR}

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL} -d ${PREFIX}/${TDIR}/'{}' \; && \
	${FIND} . -type f -exec ${INSTALL_DATA} '{}' ${PREFIX}/${TDIR}/'{}' \;

.include <bsd.port.mk>
