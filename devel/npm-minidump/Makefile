# $FreeBSD$

PORTNAME=	npm-minidump
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0-1
DISTVERSIONSUFFIX=	-gc8bc621
CATEGORIES=	devel sysutils

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Node module to process minidump files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	npm>=0:www/npm

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	electron
GH_PROJECT=	node-minidump

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/minidump
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${PREFIX}/lib/node_modules/minidump

.include <bsd.port.mk>
