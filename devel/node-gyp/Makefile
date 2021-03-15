# $FreeBSD$

PORTNAME=	gyp
DISTVERSIONPREFIX=	v
DISTVERSION=	7.1.2
CATEGORIES=	devel
PKGNAMEPREFIX=	node-

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Cross-platform command-line tool written in Node.js

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/npm:www/npm

USE_GITHUB=	yes
GH_ACCOUNT=	nodejs
GH_PROJECT=	node-gyp

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/node-gyp
	(cd ${WRKSRC} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/node-gyp \
	"! ( -name \.* -or -path *\/\.github\/* -or -name test -or -path *\/test\/* )")
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/node-gyp/bin/node-gyp.js \
		${STAGEDIR}${PREFIX}/bin/node-gyp

.include <bsd.port.mk>
