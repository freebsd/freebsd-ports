PORTNAME=	sync
DISTVERSION=	1.1.2
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Named and unnamed synchronization objects in PHP
WWW=		https://pecl.php.net/package/sync

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
