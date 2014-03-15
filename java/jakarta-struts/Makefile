# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	struts
PORTVERSION=	1.2.9
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=struts/binaries
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache Struts framework

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	YES
USES=		zip

JAVASHAREDIR=	share/java
TDIR=		${JAVASHAREDIR}/${PKGNAME}
PLIST_SUB+=	T=${TDIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL} -d ${STAGEDIR}${PREFIX}/${TDIR}/'{}' \; && \
	${FIND} . -type f -exec ${INSTALL_DATA} '{}' ${STAGEDIR}${PREFIX}/${TDIR}/'{}' \;

.include <bsd.port.mk>
