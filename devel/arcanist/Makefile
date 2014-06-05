# $FreeBSD$

PORTNAME=	arcanist
PORTVERSION=	20140508
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command line interface for Phabricator

LICENSE=	APACHE20

CONFLICTS=	arc-*

PHP_DESTDIR=	lib/php/arcanist
RUN_DEPENDS=	php5-libphutil>0:${PORTSDIR}/devel/libphutil \
		bash:${PORTSDIR}/shells/bash
USE_PHP=	curl json simplexml
USE_GITHUB=	yes
NO_BUILD=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1591b21

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	${LN} -sf ${PREFIX}/${PHP_DESTDIR}/bin/arc ${STAGEDIR}${PREFIX}/bin
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/bin/arc

.include <bsd.port.mk>
