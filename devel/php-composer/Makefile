# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	composer
DISTVERSION=	1.0.0-alpha8.20140419
CATEGORIES=	devel
MASTER_SITES=	http://getcomposer.org/download/${DISTVERSION}/ \
		http://freebsd.cs.nctu.edu.tw/~gslin/files/${PORTNAME}/${DISTVERSION}/
PKGNAMEPREFIX=	php-
DISTNAME=	composer
EXTRACT_SUFX=	.phar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Dependency Manager for PHP

LICENSE=	MIT

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	intl openssl phar

PLIST_FILES=	bin/composer \
		bin/composer.phar

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/composer.phar ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/composer.phar ${STAGEDIR}${PREFIX}/bin/
	${LN} -s composer.phar ${STAGEDIR}${PREFIX}/bin/composer

.include <bsd.port.mk>
