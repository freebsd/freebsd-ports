# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	id3
PORTVERSION=	0.2
CATEGORIES=	audio pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension to read and write ID3 tags in MP3 files

LICENSE=	PHP30

BROKEN=		Unfetchable
USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=5 56

CONFIGURE_ARGS=	--enable-id3

.include <bsd.port.mk>
