# Created by: DIrk Ye <dirk.ye@gmail.com>
# $FreeBSD$

PORTNAME=	Ice
PORTVERSION=	3.5.0
CATEGORIES=	devel
MASTER_SITES=	http://download.zeroc.com/Ice/3.5/
PKGNAMEPREFIX=	php5-

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for PHP

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:${PORTSDIR}/devel/mcpp
LIB_DEPENDS=	Ice.${LIB_VRS}:${PORTSDIR}/devel/ice

OPTIONS_DEFINE=	DEBUG DOCS NAMESPACES
NAMESPACES_DESC=	Use PHP namespaces (recommended)

USE_GMAKE=	yes
MAKE_ARGS+=	PHP_EXT_DIR=${PHP_EXT_DIR} ICE_HOME=${PREFIX} \
		PHP_HOME=${PREFIX} OPTIMIZE=yes
USE_PHP=	yes
USE_PHP_BUILD=	yes
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4 52
BUILD_WRKSRC=	${WRKSRC}/php
INSTALL_WRKSRC=	${WRKSRC}/php

LIB_VRS=	${PORTVERSION:S|.||g:C|0$||}
PHP_MODNAME?=	IcePHP

NO_STAGE=	yes
.include <bsd.port.options.mk>

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT
.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-g
.else
CFLAGS+=	-DNDEBUG
.endif

.if ${ARCH} == "ia64"
BROKEN=		does not compile on ia64
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

.if ${PORT_OPTIONS:MNAMESPACES}
MAKE_ARGS+=	USE_NAMESPACES=yes
PLIST_SUB+=	NAMESPACES=""
PLIST_SUB+=	NONAMESPACES="@comment "
.else
PLIST_SUB+=	NAMESPACES="@comment "
PLIST_SUB+=	NONAMESPACES=""
.endif

.if empty(PORT_OPTIONS:MDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%DATADIR%%|${DATADIR}|g; \
		s|%%DOCSDIR%%|${DOCSDIR}|g; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g' \
		${FILESDIR}/Make.rules.FreeBSD > ${WRKSRC}/cpp/config/Make.rules.FreeBSD
	@${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/php/config/Make.rules.php

post-install:
	@${MKDIR} ${PREFIX}/etc/php
	@${ECHO_CMD} extension=${PHP_MODNAME}.so \
		>> ${PREFIX}/etc/php/extensions.ini

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

.include <bsd.port.mk>
