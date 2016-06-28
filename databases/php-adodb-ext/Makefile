# Created by: JoeHorn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	adodb-ext
PORTVERSION=	5.04
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://phplens.com/lens/dl/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ADOdb Extension

WRKSRC=		${WRKDIR}/adodb-${PORTVERSION:S/.//}

USES=		dos2unix php:ext zip
IGNORE_WITH_PHP=56 70

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PHP_VER} == "55"
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-php54-adodb.c
.endif

.include <bsd.port.post.mk>
