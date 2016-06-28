# Created by: Muhammad Moinur Rahman<bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	raphf
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
PKGNAMESUFFIX=	2

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Resource and persistent handles factory

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^2.*

USES=		gmake php:ext tar:tgz
IGNORE_WITH_PHP=	55 56
CONFLICTS=	pecl-raphf-1*

.include <bsd.port.mk>
