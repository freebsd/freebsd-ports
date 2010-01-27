# New ports collection makefile for:	pecl-gearman
# Date created:		2010-01-27
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	UUID extension

LIB_DEPENDS=	uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--with-uuid=${LOCALBASE} CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
PHP_MODNAME=	${PORTNAME}
USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
