# Created by: chinsan
# $FreeBSD$

PORTNAME=	hidef
PORTVERSION=	0.1.13
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Constants for real

LICENSE=	PHP301

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56 70

CONFIGURE_ARGS=	--enable-hidef

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,g' \
	${WRKSRC}/hidef.c

.include <bsd.port.mk>
