# $FreeBSD$

PORTNAME=	rrd
DISTVERSION=	1.1.0
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PHP bindings to rrd tool system

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

LDFLAGS+=	-L${LOCALBASE}/lib

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
