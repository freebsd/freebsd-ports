# Created by: nbm
# $FreeBSD$

PORTNAME=	phpMyAdmin
DISTVERSION=	4.1.11
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-all-languages

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	A set of PHP-scripts to manage MySQL over the web

NO_ARCH=	yes
LICENSE=	GPLv2

USES=		shebangfix tar:xz
NO_BUILD=	yes
.if !defined(WITHOUT_PHP_DEPENDS)
IGNORE_WITH_PHP=52
USE_PHP=	ctype session filter mbstring json spl
.endif

# Note: default settings will pull in X11 client support.  If you don't
# want this, either turn off GD in the config dialog, or else turn off
# FONTCONFIG in the graphics/gd port options.

OPTIONS_DEFINE=		APC BZ2 GD MCRYPT OPENSSL PDF XML ZIP ZLIB
OPTIONS_DEFAULT=	APC BZ2 GD MCRYPT MYSQLI OPENSSL PDF XML ZIP ZLIB

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
XML_DESC=	PHP XML support (Export to OpenDoc)
ZIP_DESC=	PHP Zip compression support
ZLIB_DESC=	PHP ZLIB support

.include <bsd.port.options.mk>

WANT_PHP_WEB=	yes

GROUPS?=	${WWWGRP}
CFG_FILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PMA_GRP=${GROUPS}

SUB_LIST+=	PKGNAME=${PKGNAME}	       \
		CFG_FILE=${WWWDIR}/${CFG_FILE}
SUB_FILES+=	pkg-message

SHEBANG_FILES=	libraries/plugins/transformations/generator_main_class.sh \
		libraries/plugins/transformations/generator_plugin.sh

.if !defined(WITHOUT_PHP_DEPENDS)

.for opt in ${OPTIONS_DEFINE} ${OPTIONS_MULTI_DB_connect}
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
	${CP} ${FILESDIR}/${CFG_FILE}.sample ${WRKSRC}/${CFG_FILE}.sample ; \
	${FIND} . ! -type d ! -name ${CFG_FILE}.sample ! -name '*.bak' | \
	    ${SORT} | ${SED} -e "s,^\.,%%WWWDIR%%,"   >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk	     >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
	    -e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
	    -e "s,^\.,@dirrm %%WWWDIR%%,"	     >>${PLIST}

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore ! -name '*.bak' ) ; do \
	    dst=${STAGEDIR}${WWWDIR}$${src#.} ; \
	    if ${TEST} -d "$$src" ; then \
		${MKDIR} "$$dst" ; \
	    else \
		${INSTALL_DATA} "$$src" "$$dst" ; \
	    fi \
	done

install-conf: install-app
	${CHMOD} 0640 ${STAGEDIR}${WWWDIR}/${CFG_FILE}.sample ; \
	${CHGRP} ${WWWGRP} ${STAGEDIR}${WWWDIR}/${CFG_FILE}.sample ;

.include <bsd.port.mk>
