# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin211
DISTVERSION=	2.11.11.2
CATEGORIES=	databases www
MASTER_SITES=	SF/phpmyadmin/phpMyAdmin/${PORTVERSION}
DISTNAME=	${PORTNAME:S/211//}-${DISTVERSION}-all-languages

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to manage MySQL over the web

LICENSE=	GPLv2

USE_BZIP2=	yes
NO_BUILD=	yes
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype mysql session
.endif

OPTIONS=	SUPHP	 "suPHP support" off \
		BZ2	 "bzip2 library support" on \
		GD	 "GD library support" on \
		OPENSSL	 "OpenSSL support" on \
		PDF	 "PDFlib support (implies GD)" on \
		ZLIB	 "ZLIB support" on \
		MCRYPT	 "MCrypt library support" on \
		MBSTRING "Multi-byte character-set string support" on

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

SUB_LIST+=	PMA_USR=${USERS} \
		PMA_GRP=${GROUPS}
SUB_FILES+=	pkg-install pkg-deinstall

.endif

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

.if !defined(WITHOUT_PHP_DEPENDS)
# Options that default to on:
.for opt in BZ2 GD OPENSSL PDF ZLIB MCRYPT MBSTRING
.    if !defined(WITHOUT_${opt}) || defined(WITH_${opt})
USE_PHP+=	${opt:L}
.    endif
.endfor
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PHP_DEPENDS) && ${PHP_VER} == 4
USE_PHP+=	pcre
.endif

.SILENT:

do-build:
	@${DO_NADA}

pre-everything::
	${ECHO_MSG} ""
	${ECHO_MSG} "This is the legacy version of phpMyAdmin that will"
	${ECHO_MSG} "work with PHP4 and versions of MySQL older than 5.0"
	${ECHO_MSG} ""
	${ECHO_MSG} "Note that the mysqli option is not available with this"
	${ECHO_MSG} "port.  Please use databases/phpmyadmin instead."
	${ECHO_MSG} ""
	${ECHO_MSG} "If you want to use PHP4, for best results, please"
	${ECHO_MSG} "install lang/php4 before attempting to install"
	${ECHO_MSG} "databases/phpmyadmin"
	${ECHO_MSG} ""

# When creating a package, empty directories will not be generated
# from the pkg tarball.  Therefore make sure no directories are empty.

post-patch:
	cd ${WRKSRC} ; \
	for emptydir in $$( ${FIND} . -type d -empty -print ) ; do \
	    ${TOUCH} $${emptydir}/.keep-me ; \
	done
	${CP} ${FILESDIR}/${CFGFILE}.sample ${WRKSRC}/${CFGFILE}.sample
	cd ${WRKSRC} ; \
	${FIND} . ! -type d ! -name ${CFGFILE}.sample | ${SORT} | \
	    ${SED} -e "s,^\.,%%WWWDIR%%,"	      >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk	     >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
	     -e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
	     -e "s,^\.,@dirrm %%WWWDIR%%,"	     >>${PLIST}

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore ) ; do \
	    dst=${WWWDIR}$${src#.} ; \
	    if ${TEST} -d $$src ; then \
		${MKDIR} $$dst ; \
	    else \
		${INSTALL_DATA} $$src $$dst ; \
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

.include <bsd.port.post.mk>
