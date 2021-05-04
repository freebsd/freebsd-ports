# Created by: chinsan <chinsan.tw@gmail.com>

PORTNAME=	lzf
PORTVERSION=	1.6.8
CATEGORIES=	archivers pear
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handles LZF de/compression

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl

CONFIGURE_ARGS=	--enable-lzf

OPTIONS_DEFINE=	BETTER_COMPRESSION
BETTER_COMPRESSION_DESC=Better compression ratio

BETTER_COMPRESSION_CONFIGURE_ENABLE=	lzf-better-compression

.include <bsd.port.mk>
