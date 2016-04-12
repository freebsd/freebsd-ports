# $FreeBSD$

PORTNAME=	arcanist
PORTVERSION=	20151220
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Command line interface for Phabricator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	arc-*

PHP_DESTDIR=	lib/php/arcanist
RUN_DEPENDS=	php5-libphutil>0:devel/libphutil
USE_PHP=	curl dom json simplexml
USE_GITHUB=	yes
NO_BUILD=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	8762e3f

OPTIONS_DEFINE=	ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Support for encodings other than utf-8
ENCODINGS_USE=	PHP=mbstring

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	${LN} -sf ${PREFIX}/${PHP_DESTDIR}/scripts/arcanist.php ${STAGEDIR}${PREFIX}/bin/arc

.include <bsd.port.mk>
