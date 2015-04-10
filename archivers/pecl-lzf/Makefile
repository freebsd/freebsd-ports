# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	lzf
PORTVERSION=	1.6.2
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Handles LZF de/compression

LICENSE=	PHP202

BROKEN=		No public distfiles
USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-lzf
WRKSRC=		${WRKDIR}/${DISTNAME:tu}

OPTIONS_DEFINE=		BETTER_COMPRESSION
BETTER_COMPRESSION_DESC=	Better compression ratio
BETTER_COMPRESSION_CONFIGURE_ON=	--enable-lzf-better-compression

.include <bsd.port.mk>
