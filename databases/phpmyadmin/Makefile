# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin
DISTVERSION=	3.5.2.2
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-all-languages

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	A set of PHP-scripts to manage MySQL over the web

LICENSE=	GPLv2

IGNORE_WITH_PHP=	4
USE_XZ=	yes
NO_BUILD=	yes
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype session filter mbstring json spl
.endif

# Note: default settings will pull in X11 client support.  If you don't
# want this, either turn off GD in the config dialog, or else turn off
# FONTCONFIG in the graphics/gd port options.

PHP_MODULE_OPTIONS=	APC BZ2 GD MCRYPT OPENSSL PDF ZIP ZLIB
OPTIONS_DEFINE=		SUPHP ${PHP_MODULE_OPTIONS}
OPTIONS_DEFAULT=	APC BZ2 GD MCRYPT MYSQLI OPENSSL PDF ZIP ZLIB

OPTIONS_MULTI=		DB_connect
OPTIONS_MULTI_DB_connect=	MYSQL MYSQLI

APC_DESC=	PHP APC (animated progress bar) support
BZ2_DESC=	PHP bzip2 library support
GD_DESC=	PHP GD library support (requires X11)
MCRYPT_DESC=	PHP MCrypt library support
MYSQLI_DESC=	PHP Improved MySQL client support
MYSQL_DESC=	PHP MySQL support via mysql client
OPENSSL_DESC=	PHP OpenSSL support
PDF_DESC=	PHP PDFlib support
SUPHP_DESC=	suPHP support
ZIP_DESC=	PHP Zip compression support
ZLIB_DESC=	PHP ZLIB support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUPHP}

PKGNAMESUFFIX=	-suphp
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes

.else

WANT_PHP_WEB=	yes

.endif

# USERS is only used with the SUPHP option
GROUPS?=	${WWWGRP}
CFGFILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PMA_GRP=${GROUPS}

.if ${PORT_OPTIONS:MSUPHP}

USERS?=		_pma

SUB_LIST+=	PMA_USR=${USERS}     \
		PMA_GRP=${GROUPS}
SUB_FILES+=	pkg-install pkg-deinstall

.endif

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.if !defined(WITHOUT_PHP_DEPENDS)

.for opt in ${PHP_MODULE_OPTIONS} ${OPTIONS_MULTI_DB_connect}
.    if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:L}
.    endif
.endfor

.endif

.SILENT:

# When creating a package, empty directories will not be generated
# from the pkg tarball.	 Therefore make sure no directories are empty.

post-patch:
	cd ${WRKSRC} ; \
	for emptydir in $$( ${FIND} . -type d -empty -print ) ; do \
	    ${TOUCH} $${emptydir}/.keep-me ; \
	done ; \
	${CP} ${FILESDIR}/${CFGFILE}.sample ${WRKSRC}/${CFGFILE}.sample ; \
	${FIND} . ! -type d ! -name ${CFGFILE}.sample ! -name '*.bak' | \
	    ${SORT} | ${SED} -e "s,^\.,%%WWWDIR%%,"   >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk	     >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
	    -e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
	    -e "s,^\.,@dirrm %%WWWDIR%%,"	     >>${PLIST}

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore ! -name '*.bak' ) ; do \
	    dst=${WWWDIR}$${src#.} ; \
	    if ${TEST} -d "$$src" ; then \
		${MKDIR} "$$dst" ; \
	    else \
		${INSTALL_DATA} "$$src" "$$dst" ; \
	    fi \
	done

install-conf: install-app
	cd ${WWWDIR} ; \
	${CHMOD} 0640 ${CFGFILE}.sample ; \
	${CHGRP} ${WWWGRP} ${CFGFILE}.sample ; \
	if ${TEST} ! -f ${CFGFILE} ; then \
	    ${CP} -p ${CFGFILE}.sample ${CFGFILE} ; \
	fi

post-install:
.if ${PORT_OPTIONS:MSUPHP}
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
