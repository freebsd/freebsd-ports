# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin
DISTVERSION=	3.3.4
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-all-languages

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to manage MySQL over the web

LICENSE=	GPLv2

USE_MYSQL=	yes
IGNORE_WITH_PHP=	4
IGNORE_WITH_MYSQL=	323 40 41
USE_BZIP2=	yes
NO_BUILD=	yes
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype mysql session filter mbstring
.endif

OPTIONS=	SUPHP	 "suPHP support" off \
		BZ2	 "bzip2 library support" on \
		GD	 "GD library support" on \
		MYSQLI	 "Improved MySQL support" off \
		OPENSSL	 "OpenSSL support" on \
		PDF	 "PDFlib support (implies GD)" on \
		ZLIB	 "ZLIB support" on \
		MCRYPT	 "MCrypt library support" on \
		ZIP	 "Zip compression support" on

.include <bsd.port.options.mk>

.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)

PKGNAMESUFFIX=	-suphp
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes

.else

WANT_PHP_WEB=	yes

.endif

# USERS is only used WITH_SUPHP
GROUPS?=	${WWWGRP}
CFGFILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PMA_GRP=${GROUPS}

.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)

USERS?=		_pma

SUB_LIST+=	PMA_USR=${USERS}     \
		PMA_GRP=${GROUPS}
SUB_FILES+=	pkg-install pkg-deinstall

.endif

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.if !defined(WITHOUT_PHP_DEPENDS)

# Options that default to on:
.for opt in BZ2 GD OPENSSL PDF ZLIB MCRYPT MBSTRING ZIP
.    if !defined(WITHOUT_${opt}) || defined(WITH_${opt})
USE_PHP+=	${opt:L}
.    endif
.endfor

# Options that default to off:
.for opt in MYSQLI
.    if defined(WITH_${opt}) && !defined(WITHOUT_${opt})
USE_PHP+=	${opt:L}
.    endif
.endfor
.endif

.SILENT:

pre-everything::
	${ECHO_MSG} "This version of phpmyadmin requires PHP 5.2+ and MySQL"
	${ECHO_MSG} "5.0+.  If you need to use an older version of PHP or"
	${ECHO_MSG} "manage older MYSQL databases, please use the"
	${ECHO_MSG} "databases/phpmyadmin211 port instead."
	${ECHO_MSG} ""

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
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
