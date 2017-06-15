# $FreeBSD$

PORTNAME=	arcanist
PORTVERSION=	20161003
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Command line interface for Phabricator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	arc-*

PHP_DESTDIR=	lib/php/arcanist
RUN_DEPENDS=	php5-libphutil>0:devel/libphutil
USES=		php
USE_PHP=	curl dom json simplexml
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	483e985

OPTIONS_DEFINE=	ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Support for encodings other than utf-8
ENCODINGS_USE=	PHP=mbstring

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	${LN} -sf ../${PHP_DESTDIR}/scripts/arcanist.php ${STAGEDIR}${PREFIX}/bin/arc

.include <bsd.port.mk>
