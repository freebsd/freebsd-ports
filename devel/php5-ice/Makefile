# New ports collection makefile for:	php-ice
# Date created:				2007-08-21
# Whom:					DIrk Ye <dirk.ye@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Ice
PORTVERSION=	3.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.zeroc.com/download/Ice/3.3/ \
		http://www.dirk.sh/dirk/Ice/
PKGNAMEPREFIX=	php5-
DISTNAME=	Ice-${PORTVERSION}

MAINTAINER=	dirk.ye@gmail.com
COMMENT=	An Ice (Internet Communications Engine) language mapping for PHP

LIB_DEPENDS=	Ice.${LIB_VRS}:${PORTSDIR}/devel/ice

USE_GMAKE=	yes
MAKE_ARGS+=	PHP_EXT_DIR=${PHP_EXT_DIR}
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4
USE_PHP=	yes
USE_PHP_BUILD=	yes
BUILD_WRKSRC=	${WRKSRC}/php
INSTALL_WRKSRC=	${WRKSRC}/php

LIB_VRS=	${PORTVERSION:S|.||g:C|1$||}
PHP_MODNAME?=	IcePHP

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT ${PTHREAD_CFLAGS}
.if defined(DEBUG)
CFLAGS+=	-g
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>
.if ${ARCH} == "ia64"
BROKEN=		does not compile on ia64
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/php/config/Make.rules
	${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/php/config/Make.rules
post-install:
	@${MKDIR} ${PREFIX}/etc/php
	@${ECHO_CMD} extension=${PHP_MODNAME}.so \
		>> ${PREFIX}/etc/php/extensions.ini
	@${CAT} ${PKGMESSAGE}

add-plist-info:
	@${ECHO_CMD} "@exec mkdir -p %D/etc/php" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo extension=${PHP_MODNAME}.so >> %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec cp %D/etc/php/extensions.ini %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec grep -v extension=${PHP_MODNAME}\\\.so %D/etc/php/extensions.ini.orig > %D/etc/php/extensions.ini || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec [ -s %D/etc/php/extensions.ini ] || rm %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/etc/php 2> /dev/null || true" \
		>> ${TMPPLIST}

security-check:
	@${ECHO_CMD} "****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following line has been added to your ${PREFIX}/etc/php/extensions.ini"
	@${ECHO_CMD} "configuration file to automatically load the installed extension:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "****************************************************************************"

.include <bsd.port.post.mk>
