# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	libpuzzle
PORTVERSION=	0.11
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://download.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/release/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	PHP extension for Puzzle library to find similar pictures

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC:H:H}/COPYING

LIB_DEPENDS=	libpuzzle.so:graphics/libpuzzle \
		libgd.so:graphics/gd

USES=		php:ext tar:bzip2
IGNORE_WITH_PHP=	71 72 73

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/php/${PORTNAME}

pre-install:
	@${STRIP_CMD} ${WRKSRC}/modules/libpuzzle.so

.include <bsd.port.mk>
