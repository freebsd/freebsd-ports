PORTNAME=	rar
PORTVERSION=	4.2.0
CATEGORIES=	archivers pear

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	PECL extension to create and read RAR files

LICENSE=	PHP301

USES=		compiler:c11 php:pecl
USE_PHP=	spl:build
IGNORE_WITH_PHP=	81 82

CONFIGURE_ARGS=	--enable-rar

.include <bsd.port.mk>
