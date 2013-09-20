# Created by: chinsan
# $FreeBSD$

PORTNAME=	hidef
PORTVERSION=	0.1.13
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Constants for real

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-hidef

CFLAGS+=-I${LOCALBASE}/include
LDFLAGS+=-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,g' \
	${WRKSRC}/hidef.c

.include <bsd.port.mk>
