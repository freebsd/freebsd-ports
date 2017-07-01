# $FreeBSD$

PORTNAME=	arcanist
PORTVERSION=	20170630
CATEGORIES=	devel
PKGNAMEPREFIX=	php-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Command line interface for Phabricator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	arc-*

PHP_DESTDIR=	lib/php/arcanist
RUN_DEPENDS=	php-libphutil>0:devel/libphutil
USES=		php
USE_PHP=	curl dom json simplexml
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	c04f141

OPTIONS_DEFINE=	ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Support for encodings other than utf-8
ENCODINGS_USE=	PHP=mbstring

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	${LN} -sf ../${PHP_DESTDIR}/scripts/arcanist.php ${STAGEDIR}${PREFIX}/bin/arc

.include <bsd.port.mk>
