# New ports collection makefile for:	dbg_php4
# Date created:		Sun Jan 26 20:47:49 GMT 2003
# Whom:			Jens Rehsack <rehsack@liwing.de>
#
# $FreeBSD$
#

PORTNAME=	dbg
PORTVERSION=	2.11.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dd.cron.ru/dbg/dnld/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	rehsack@liwing.de
COMMENT=	Debugger for PHP4

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf \
		phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/bin/php:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/dbg
CONFIGURE_ARGS=	--enable-dbg=shared --with-dbg-profiler \
		--with-php-config=${PREFIX}/bin/php-config
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

PHPCONFIG=	${LOCALBASE}/bin/php-config
.if exists(${PHPCONFIG})
PHPEXTENSIONS!=	${PHPCONFIG} --extension-dir
.else
PHPEXTENSIONS=	${LOCALBASE}/lib/php/extensions
.endif

post-extract:
	@${ECHO_MSG} "===>  PHPizing for ${DISTNAME}"
	@cd ${WRKSRC} && ${LOCALBASE}/bin/phpize

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PHPEXTENSIONS%%|${PHPEXTENSIONS}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${SED} "s|%%PHPEXTENSIONS%%|${PHPEXTENSIONS}|g" < ${.CURDIR}/pkg-plist | \
		${SED} "s|${LOCALBASE}/||" >${PLIST}

do-install:
	@${MKDIR} ${PHPEXTENSIONS}
	@${INSTALL_DATA} ${WRKSRC}/modules/dbg.so \
		${PHPEXTENSIONS}

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.post.mk>
