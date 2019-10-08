# $FreeBSD$

PORTNAME?=	arcanist
PORTVERSION?=	20190622
CATEGORIES?=	devel
PKGNAMESUFFIX=	${SLAVE_PKGNAMESUFFIX}${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT?=	Libraries for the command line interface for Phabricator

SLAVEPORT?=	lib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}libphutil>=20190831:devel/libphutil@${PHP_FLAVOR}

PHP_DESTDIR=	lib/php/arcanist
USES=		php:flavors python:2.7,env shebangfix
SHEBANG_FILES=	scripts/breakout.py
USE_PHP=	curl dom hash json simplexml zlib
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
PORTSCOUT=	ignore:1
GH_ACCOUNT=	phacility
GH_TAGNAME=	feb5f4d
PLIST=		${.CURDIR}/pkg-plist

.if ${SLAVEPORT} == lib
SLAVE_PKGNAMESUFFIX=	-${SLAVEPORT}

OPTIONS_DEFINE=	ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Support for encodings other than utf-8
ENCODINGS_USE=	PHP=mbstring

.else # link only

RUN_DEPENDS=	arcanist-lib${PHP_PKGNAMESUFFIX}>0:devel/arcanist-lib@${PHP_FLAVOR}

NO_BUILD=	yes

CONFLICTS=	arc

PLIST_FILES=	bin/arc

.endif

do-install:
.if ${SLAVEPORT} == bin
	${RLN} ../${PHP_DESTDIR}/scripts/arcanist.php ${STAGEDIR}${PREFIX}/bin/arc
.else
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${RLN} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/resources/shell/bash-completion ${STAGEDIR}${PREFIX}/share/bash-completion/completions/arc
.endif

.include <bsd.port.mk>
