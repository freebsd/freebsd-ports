# Created by: DIrk Ye <dirk.ye@gmail.com>
# $FreeBSD$

CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for PHP

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:devel/mcpp \
		slice2php:devel/ice
LIB_DEPENDS=	libIce.so.${LIB_VRS}:devel/ice

OPTIONS_DEFINE=	DEBUG NAMESPACES
OPTIONS_DEFAULT=
NAMESPACES_DESC=	Use PHP namespaces (recommended)

SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../ice
PLIST=		${.CURDIR}/pkg-plist

MAKE_ARGS+=	PHP_EXT_DIR=${PHP_EXT_DIR} ICE_HOME=${LOCALBASE} \
		PHP_HOME=${LOCALBASE} OPTIMIZE=yes
USES+=	php:build,flavors
IGNORE_WITH_PHP=71 72 73
BUILD_WRKSRC=	${WRKSRC}/php
INSTALL_WRKSRC=	${WRKSRC}/php

LIB_VRS=	${PORTVERSION:S|.||g:C|0$||}
PHP_MODNAME?=	IcePHP

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/*.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so" > ${STAGEDIR}${PREFIX}/etc/php/ext-20-ice.ini

security-check:
	@${ECHO_CMD} "****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following line has been added to your ${PREFIX}/etc/php/ext-20-ice.ini"
	@${ECHO_CMD} "configuration file to automatically load the installed extension:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "****************************************************************************"

.include "${MASTERDIR}/Makefile"
