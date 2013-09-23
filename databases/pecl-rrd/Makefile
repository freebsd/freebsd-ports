# $FreeBSD$

PORTNAME=	rrd
DISTVERSION=	1.1.1
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PHP bindings to rrd tool system

LICENSE=	PHP301

LIB_DEPENDS=	librrd.so:${PORTSDIR}/databases/rrdtool

LDFLAGS+=	-L${LOCALBASE}/lib

USE_PHP=	yes
USE_PHPEXT=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
