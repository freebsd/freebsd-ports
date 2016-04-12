# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	ladon
PORTVERSION=	1.0.6
CATEGORIES=	deskutils

MAINTAINER=	cpm@fbsd.es
COMMENT=	Utility to process many files in parallel

LICENSE=	MIT

BROKEN=		does not build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-04-15

BUILD_DEPENDS=	npm>0:www/npm
RUN_DEPENDS=	npm>0:www/npm

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	danielgtaylor

do-install:
	(cd ${STAGEDIR}${PREFIX}/lib && ${SETENV} \
		HOME=${WRKDIR} npm install --ignore-scripts ${WRKSRC})

	# this is a dirty hack
	${LN} -s ${PREFIX}/lib/node_modules/.bin/ladon ${STAGEDIR}${PREFIX}/bin/ladon

.include <bsd.port.mk>
