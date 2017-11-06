# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	npm-clean-css
PORTVERSION=	4.1.1
DISTVERSIONPREFIX=		v
CATEGORIES=	devel www

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Fast and efficient CSS optimizer for node.js and the Web

LICENSE=	APACHE20

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	npm>=0:www/npm \
		${LOCALBASE}/lib/node_modules/source-map/source-map.js:devel/npm-source-map \
		${LOCALBASE}/lib/node_modules/commander/index.js:devel/npm-commander

USE_GITHUB=	yes
GH_ACCOUNT=	jakubpawlowicz
GH_PROJECT=	clean-css

# npm install both builds and installs.  To avoid building in the stage phase,
# allow npm to install in a temporary directory and move from there.
# Moreover, only a fraction of what is installed by npm needs to be packaged
do-build:
	${MKDIR} ${WRKDIR}/build-lib
	(cd ${WRKDIR}/build-lib && \
		${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/ && \
	${MV} ${WRKDIR}/build-lib/node_modules/clean-css \
		${STAGEDIR}${PREFIX}/lib/node_modules/

.include <bsd.port.mk>
