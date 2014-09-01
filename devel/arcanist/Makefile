# $FreeBSD$

PORTNAME=	arcanist
PORTVERSION=	20140828
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command line interface for Phabricator

LICENSE=	APACHE20

CONFLICTS=	arc-*

PHP_DESTDIR=	lib/php/arcanist
RUN_DEPENDS=	php5-libphutil>0:${PORTSDIR}/devel/libphutil
USE_PHP=	curl json simplexml
USE_GITHUB=	yes
NO_BUILD=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	2c3268f

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	${LN} -sf ${PREFIX}/${PHP_DESTDIR}/scripts/arcanist.php ${STAGEDIR}${PREFIX}/bin/arc

.include <bsd.port.mk>
