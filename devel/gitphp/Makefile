# $FreeBSD$

PORTNAME=	gitphp
PORTVERSION=	0.2.8
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	https://github.com/xiphux/gitphp/releases/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based git repository browser written in PHP

LICENSE=	GPLv2

USES=		gettext php:web tar:bzip2
USE_PHP=	bz2 fileinfo mbstring memcache posix simplexml spl zlib

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdiff.so:textproc/pecl-xdiff2@${PHP_FLAVOR}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} \
		 && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${FIND} ${STAGEDIR}${WWWDIR} -type f -exec ${CHMOD} 644 {} +

.include <bsd.port.mk>
