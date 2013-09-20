# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	statgrab
PORTVERSION=	0.6.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	Statgrab-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A PECL extension to retrieve information from libstatgrab

LIB_DEPENDS=	statgrab.8:${PORTSDIR}/devel/libstatgrab

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -ldevstat ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-statgrab=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.mk>
