# Created by: nbm
# $FreeBSD$

PORTNAME=	phpMyAdmin
DISTVERSION=	4.6.3
CATEGORIES=	databases www
MASTER_SITES=	https://files.phpmyadmin.net/${PORTNAME}/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-all-languages

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Set of PHP-scripts to manage MySQL over the web

NO_ARCH=	yes
LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

USES=		cpe shebangfix tar:xz
CPE_PRODUCT=	${PORTNAME:tl}

NO_BUILD=	yes
.if !defined(WITHOUT_PHP_DEPENDS)
IGNORE_WITH_PHP=5 54
USE_PHP=	ctype session filter mbstring json spl mysqli
.endif

# Note: default settings will pull in X11 client support.  If you don't
# want this, either turn off GD in the config dialog, or else turn off
# FONTCONFIG in the graphics/gd port options.

OPTIONS_DEFINE=		BZ2 GD MCRYPT OPENSSL PDF XML ZIP ZLIB
OPTIONS_DEFAULT=	BZ2 GD MCRYPT OPENSSL XML ZIP ZLIB

BZ2_DESC=	PHP bzip2 library support
GD_DESC=	PHP GD library support (requires X11)
MCRYPT_DESC=	PHP MCrypt library support
OPENSSL_DESC=	PHP OpenSSL support
PDF_DESC=	PHP PDFlib support
XML_DESC=	PHP XML support (Export to OpenDoc)
ZIP_DESC=	PHP Zip compression support
ZLIB_DESC=	PHP ZLIB support

.include <bsd.port.options.mk>

WANT_PHP_WEB=	yes

GROUPS?=	${WWWGRP}
CFG_FILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PMA_GRP=${GROUPS}

SUB_LIST+=	PKGNAME=${PKGNAME}	        \
		CFG_FILE=${WWWDIR}/${CFG_FILE}
SUB_FILES+=	pkg-message

SHEBANG_FILES=	libraries/plugins/transformations/generator_main_class.sh \
		libraries/plugins/transformations/generator_plugin.sh

.if !defined(WITHOUT_PHP_DEPENDS)

.for opt in ${OPTIONS_DEFINE} ${OPTIONS_MULTI_DB_connect}
.    if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:tl}
.    endif
.endfor

.endif

.SILENT:

post-patch:
	cd ${WRKSRC} ; \
	${CP} ${FILESDIR}/${CFG_FILE}.sample ${WRKSRC}/${CFG_FILE}.sample ; \
	${FIND} . ! -type d ! -name ${CFG_FILE}.sample ! -name '*.bak' | \
	    ${SORT} | ${SED} -e "s,^\.,%%WWWDIR%%,"   >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk	     >>${PLIST} ; \
	for emptydir in $$( ${FIND} . -type d -empty -print ) ; do \
	    ${ECHO} "@dir(,,)$${emptydir}"	     >>${PLIST} ; \
	done ; \

do-install:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore ! -name '*.bak' ) ; do \
	    dst=${STAGEDIR}${WWWDIR}$${src#.} ; \
	    if ${TEST} -d "$$src" ; then \
		${MKDIR} "$$dst" ; \
	    else \
		${INSTALL_DATA} "$$src" "$$dst" ; \
	    fi \
	done

.include <bsd.port.mk>
