# Created by: Muhammad Moinur Rahman<bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	propro
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
PKGNAMESUFFIX=	2

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Facility to manage extension object properties

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^2.*

USES=		gmake php:ext tar:tgz
IGNORE_WITH_PHP=	56
CONFLICTS=	pecl-propro-1*

.include <bsd.port.mk>
