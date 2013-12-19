# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fribidi
PORTVERSION=	1.2
CATEGORIES=	converters pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension for the Unicode Bidi algorithm

LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi

USES=		pkgconfig
USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-fribidi=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.mk>
