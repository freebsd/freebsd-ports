# New ports collection makefile for:	pecl-gearman
# Date created:		2009-07-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gearman
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	gslin@gslin.org
COMMENT=	Gearman API

LIB_DEPENDS=	gearman:${PORTSDIR}/devel/gearmand

CONFIGURE_ARGS=	--with-gearman
PHP_MODNAME=	${PORTNAME}
USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 700000
BROKEN=		does not compile
.endif

.include <bsd.port.post.mk>
