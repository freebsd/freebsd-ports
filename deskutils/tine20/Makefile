# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tine20
PORTVERSION=	0.0.2017.02.2
DISTVERSIONSUFFIX=	2017.02.2
CATEGORIES=	deskutils www
MASTER_SITES=	http://packages.tine20.org/source/${DISTVERSIONSUFFIX}/
DISTNAME=	${PORTNAME}-allinone_${DISTVERSIONSUFFIX}

MAINTAINER=	udo.rader@bestsolution.at
COMMENT=	Professional Open Source Groupware and CRM

LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:bzip2 gettext
NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions -C ${WRKSRC}

SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

OPTIONS_DEFINE=	LDAP MEMCACHE
MEMCACHE_DESC=	Enable pecl-memcache support

USE_MYSQL=	yes
USE_PHP=	ctype dom gd iconv json mcrypt pdo_mysql simplexml \
		spl xml zip
WANT_PHP_WEB=	yes

LDAP_USE=	php=ldap
MEMCACHE_USE=	php=memcache

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
