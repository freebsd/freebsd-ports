# New ports collection makefile for:	pecl-ncurses
# Date created:			29 Apr 2010
# Whom:				Jille Timmermans <jille@quis.cx>
#
# $FreeBSD$
#

PORTNAME=	ncurses
PORTVERSION=	1.0.1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	jille@quis.cx
COMMENT=	A PECL extension for ncurses

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
WANT_PHP_CLI=	yes

CONFLICTS=	php52-[0-9]

.include <bsd.port.mk>
