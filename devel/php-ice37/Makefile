CATEGORIES=		devel
PKGNAMEPREFIX=		${PHP_PKGNAMEPREFIX}

MAINTAINER=		grembo@FreeBSD.org
COMMENT=		Ice (Internet Communications Engine) language mapping for PHP

LICENSE=		GPLv2

BUILD_DEPENDS=		mcpp:devel/mcpp \
			slice2php:devel/ice37
LIB_DEPENDS=		libIce.so.${LIB_VRS}:devel/ice37

OPTIONS_DEFINE=		DEBUG NAMESPACES
NAMESPACES_DESC=	Use PHP namespaces (recommended)
OPTIONS_DEFAULT=	NAMESPACES

SLAVE_PORT=		yes
MASTERDIR=		${.CURDIR}/../ice37
PLIST=			${.CURDIR}/pkg-plist

MAKE_ARGS+=		PHP_EXT_DIR=${PHP_EXT_DIR} ICE_HOME=${LOCALBASE} \
			PHP_HOME=${LOCALBASE} OPTIMIZE=yes
USES+=			php:build,flavors
BUILD_WRKSRC=		${WRKSRC}/php
INSTALL_WRKSRC=		${WRKSRC}/php

NAMESPACES_MAKE_ENV_OFF=USE_NAMESPACES=no

LIB_VRS=		${PORTVERSION:S|.||g:C|0$||}
PHP_MODNAME?=		ice

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
