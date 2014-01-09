# Created by: DIrk Ye <dirk.ye@gmail.com>
# $FreeBSD$

CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for PHP

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:${PORTSDIR}/devel/mcpp \
		slice2php:${PORTSDIR}/devel/ice
LIB_DEPENDS=	Ice.${LIB_VRS}:${PORTSDIR}/devel/ice

OPTIONS_DEFINE=	DEBUG DOCS NAMESPACES
OPTIONS_DEFAULT=
NAMESPACES_DESC=	Use PHP namespaces (recommended)

SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../ice
PLIST=		${.CURDIR}/pkg-plist

MAKE_ARGS+=	PHP_EXT_DIR=${PHP_EXT_DIR} ICE_HOME=${LOCALBASE} \
		PHP_HOME=${LOCALBASE} OPTIMIZE=yes
USE_PHP=	yes
USE_PHP_BUILD=	yes
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4 52
BUILD_WRKSRC=	${WRKSRC}/php
INSTALL_WRKSRC=	${WRKSRC}/php

LIB_VRS=	${PORTVERSION:S|.||g:C|0$||}
PHP_MODNAME?=	IcePHP

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php

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

.include "${MASTERDIR}/Makefile"
