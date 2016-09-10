# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	struts
PORTVERSION=	1.2.9
CATEGORIES=	java devel
MASTER_SITES=	APACHE/${PORTNAME}/binaries
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache Struts framework

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	YES
USES=		cpe zip
CPE_VENDOR=	apache

JAVASHAREDIR=	share/java
TDIR=		${JAVASHAREDIR}/${PKGNAME}
PLIST_SUB+=	T=${TDIR}

DEPRECATED=	Port is unmaintained and has known security vulnerabilites
EXPIRATION_DATE=2016-12-01

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL} -d ${STAGEDIR}${PREFIX}/${TDIR}/'{}' \; && \
	${FIND} . -type f -exec ${INSTALL_DATA} '{}' ${STAGEDIR}${PREFIX}/${TDIR}/'{}' \;

.include <bsd.port.mk>
