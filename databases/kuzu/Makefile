PORTNAME=	kuzu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.3
CATEGORIES=	databases

MAINTAINER=	mahlon@martini.nu
COMMENT=	Embeddable, scalable, extremely fast graph database
WWW=		https://kuzudb.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream repository archived on Oct 11, 2025

USES=		cmake ninja:build python:3.9+,build

USE_GITHUB=	yes
GH_ACCOUNT=	kuzudb

USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${DISTVERSION}

post-install:
	${MV}  ${STAGEDIR}${PREFIX}/lib/libkuzu.so ${STAGEDIR}${PREFIX}/lib/libkuzu.so.${DISTVERSION}
	${RLN} libkuzu.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libkuzu.so
	${RLN} libkuzu.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libkuzu.so.0

.include <bsd.port.mk>
