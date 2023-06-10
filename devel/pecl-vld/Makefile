PORTNAME=	vld
PORTVERSION=	0.18.0
CATEGORIES=	devel pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dump the internal representation of PHP scripts
WWW=		https://pecl.php.net/package/vld

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl

CONFIGURE_ARGS=	--enable-vld
IGNORE_WITH_PHP=82 83

.include <bsd.port.mk>
