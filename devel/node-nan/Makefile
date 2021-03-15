# $FreeBSD$

PORTNAME=	nan
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.2
CATEGORIES=	devel
PKGNAMEPREFIX=	node-

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Native Abstractions for Node.js

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	nodejs

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/nan
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/lib/node_modules/nan \
		"! ( -name \.* -or -path *\/test\/* -or -name test )"

.include <bsd.port.mk>
