# $FreeBSD$

PORTNAME=	arcanist
PORTVERSION=	20181231
CATEGORIES=	devel
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Command line interface for Phabricator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}libphutil>0:devel/libphutil@${PHP_FLAVOR}

CONFLICTS=	arc-*

PHP_DESTDIR=	lib/php/arcanist
USES=		php:flavors python:2.7,env shebangfix
SHEBANG_FILES=	scripts/breakout.py
USE_PHP=	curl dom hash json simplexml
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	25c2381

OPTIONS_DEFINE=	ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Support for encodings other than utf-8
ENCODINGS_USE=	PHP=mbstring

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	${LN} -sf ../${PHP_DESTDIR}/scripts/arcanist.php ${STAGEDIR}${PREFIX}/bin/arc
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${RLN} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/resources/shell/bash-completion ${STAGEDIR}${PREFIX}/share/bash-completion/completions/arc

.include <bsd.port.mk>
