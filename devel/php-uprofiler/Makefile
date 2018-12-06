# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	uprofiler
PORTVERSION=	0.11.0.20150219
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Lightweight profiler for PHP

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_aarch64=		invokes x86 assembler
BROKEN_armv6=		invokes x86 assembler
BROKEN_armv7=		invokes x86 assembler
BROKEN_mips64=		invokes x86 assembler
BROKEN_powerpc64=	invokes x86 assembler
BROKEN_sparc64=		invokes x86 assembler

USE_GITHUB=	yes
GH_ACCOUNT=	FriendsOfPHP
GH_TAGNAME=	483c1e5

WRKSRC_SUBDIR=	extension
USES=		php:ext
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
