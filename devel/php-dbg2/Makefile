# New ports collection makefile for:	dbg_php4
# Date created:		Sun Jan 26 20:47:49 GMT 2003
# Whom:			Jens Rehsack <rehsack@liwing.de>
#
# $FreeBSD$
#

PORTNAME=	dbg
PORTVERSION=	2.11.30
CATEGORIES=	devel
MASTER_SITES=	http://dd.cron.ru/dbg/dnld/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	rehsack@liwing.de
COMMENT=	Debugger for PHP4

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PHP=	yes
USE_PHPIZE=	yes
CONFIGURE_ARGS=	--enable-dbg=shared --with-dbg-profiler
#CONFIGURE_ENV=	with_dbg_trace=1
PKGMESSAGE=	${WRKDIR}/pkg-message

post-build:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g;s|%%PHP_EXT_DIR%%|${PHP_EXT_DIR}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/dbg.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
