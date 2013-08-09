# New ports collection makefile for:	php-libpuzzle
# Date created:				18 May 2010
# Whom:					Naram Qashat <cyberbotx@cyberbotx.com>
#
# $FreeBSD$
#

PORTNAME=	libpuzzle
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/release/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/
PKGNAMEPREFIX=	php-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	PHP extension for Puzzle library to find similar pictures

LIB_DEPENDS=	puzzle.1:${PORTSDIR}/graphics/libpuzzle \
		gd:${PORTSDIR}/graphics/gd

LICENSE=	BSD
LICENSE_FILES=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/php/${PORTNAME}

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes

.include <bsd.port.mk>
