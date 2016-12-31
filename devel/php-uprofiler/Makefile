# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	uprofiler
PORTVERSION=	0.11.0.20150219
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	php-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Lightweight profiler for PHP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_aarch64=		Does not build: invokes x86 asm
BROKEN_mips64=		Does not build: invokes x86 asm
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build: invokes x86 asm

USE_GITHUB=	yes
GH_ACCOUNT=	FriendsOfPHP
GH_TAGNAME=	483c1e5

WRKSRC_SUBDIR=	extension
USES=		php:ext
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
