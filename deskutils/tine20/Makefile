# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tine20
PORTVERSION=	0.0.2018.08.6
DISTVERSIONSUFFIX=	2018.08.6
CATEGORIES=	deskutils www
MASTER_SITES=	http://packages.tine20.org/source/${DISTVERSIONSUFFIX}/
DISTNAME=	${PORTNAME}-allinone_${DISTVERSIONSUFFIX}

MAINTAINER=	udo.rader@bestsolution.at
COMMENT=	Professional Open Source Groupware and CRM

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/share/pear/Date.php:devel/pear-Date@${PHP_FLAVOR}

USES=		gettext mysql php:web php:flavors tar:bzip2

LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions -C ${WRKSRC}

SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

OPTIONS_DEFINE=	LDAP MEMCACHE REDIS
MEMCACHE_DESC=	Enable pecl-memcache support
REDIS_DESC=	Enable Redis support

USE_PHP=	ctype dom gd iconv json mcrypt pdo_mysql simplexml \
		spl xml zip openssl hash mbstring

LDAP_USE=	php=ldap
MEMCACHE_USE=	php=memcache
REDIS_USE=	php=redis

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
