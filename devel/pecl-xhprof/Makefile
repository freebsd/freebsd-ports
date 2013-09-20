# Created by: Conor McDermottroe <ports@mcdermottroe.com>
# $FreeBSD$

PORTNAME=	xhprof
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@mcdermottroe.com
COMMENT=	A Hierarchical Profiler for PHP

WRKSRC=		${WRKDIR}/${DISTNAME}/extension

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
ONLY_FOR_ARCHS=	i386 amd64

NO_STAGE=	yes
.include <bsd.port.mk>
