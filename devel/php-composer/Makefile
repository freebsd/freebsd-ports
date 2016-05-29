# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	composer
DISTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://getcomposer.org/download/${DISTVERSION}/
PKGNAMEPREFIX=	php-
DISTNAME=	composer
EXTRACT_SUFX=	.phar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Dependency Manager for PHP

LICENSE=	MIT

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	intl openssl phar json ctype

PLIST_FILES=	bin/composer \
		bin/composer.phar

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/composer.phar ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/composer.phar ${STAGEDIR}${PREFIX}/bin/
	${LN} -s composer.phar ${STAGEDIR}${PREFIX}/bin/composer

.include <bsd.port.mk>
