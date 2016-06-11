# $FreeBSD$

PORTNAME=	newt
PORTVERSION=	1.2.9
CATEGORIES=	devel www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP language extension for RedHat Newt library

LICENSE=	PHP301

LIB_DEPENDS=	libnewt.so:devel/newt

USES=		tar:tgz
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	newt
IGNORE_WITH_PHP=	70

post-patch:
	@${REINPLACE_CMD} -e '/SEARCH_PATH/ s,=",="${LOCALBASE} ${PREFIX} ,' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
