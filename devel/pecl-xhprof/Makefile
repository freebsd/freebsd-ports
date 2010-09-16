# New ports collection makefile for:    pecl-xhprof
# Date created:                 2 Jul 2010
# Whom:                         Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	xhprof
PORTVERSION=	0.9.2
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700110
BROKEN=	Requires cpuset support
.endif

.include <bsd.port.post.mk>
