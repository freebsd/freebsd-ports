# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pdo_user
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	PDO_USER-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	PECL classes provides a Userspace interface for PDO drivers

WRKSRC=		${WRKDIR}/PDO_USER-${PORTVERSION}

USES=		php:ext
USE_PHP=	pdo:build
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
