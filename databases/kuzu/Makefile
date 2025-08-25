PORTNAME=	kuzu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.2
CATEGORIES=	databases

MAINTAINER=	mahlon@martini.nu
COMMENT=	Embeddable, scalable, extremely fast graph database
WWW=		https://kuzudb.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake ninja:build python:3.9+,build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kuzudb

PLIST_SUB=	VERSION=${DISTVERSION}

post-install:
	${MV}  ${STAGEDIR}${PREFIX}/lib/libkuzu.so ${STAGEDIR}${PREFIX}/lib/libkuzu.so.${DISTVERSION}
	${RLN} libkuzu.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libkuzu.so
	${RLN} libkuzu.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libkuzu.so.0

.include <bsd.port.mk>
