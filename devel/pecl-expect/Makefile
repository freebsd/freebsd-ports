# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	0.3.1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP extension for expect library

LIB_DEPENDS=	libexpect.so:${PORTSDIR}/lang/expect

LICENSE=	PHP301

USES=		tcl:86
USE_PHP=	yes
USE_PHPEXT=	yes

CFLAGS+=	-I${TCL_INCLUDEDIR}
CONFIGURE_ARGS+=--with-expect=${LOCALBASE}

.include <bsd.port.mk>
