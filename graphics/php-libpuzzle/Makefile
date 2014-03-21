# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	libpuzzle
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/release/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/
PKGNAMEPREFIX=	php-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	PHP extension for Puzzle library to find similar pictures

LICENSE=	BSD2CLAUSE
LICENSE_FILES=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpuzzle.so:${PORTSDIR}/graphics/libpuzzle \
		libgd.so:${PORTSDIR}/graphics/gd

USES=		tar:bzip2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/php/${PORTNAME}

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes

pre-install:
	@${STRIP_CMD} ${WRKSRC}/modules/libpuzzle.so

.include <bsd.port.mk>
