# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	npm-graceful-readlink
PORTVERSION=	1.0.1
CATEGORIES=	devel www

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Graceful fs.readlink

LICENSE=	APACHE20

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	npm>=0:www/npm

USE_GITHUB=	yes
GH_ACCOUNT=	zhiyelee
GH_PROJECT=	graceful-readlink

# npm install both builds and installs.  To avoid building in the stage phase,
# allow npm to install in a temporary directory and move from there.
# Moreover, only a fraction of what is installed by npm needs to be packaged
do-build:
	${MKDIR} ${WRKDIR}/build-lib
	(cd ${WRKDIR}/build-lib && \
		${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/ && \
	${MV} ${WRKDIR}/build-lib/node_modules/graceful-readlink \
		${STAGEDIR}${PREFIX}/lib/node_modules/

.include <bsd.port.mk>
