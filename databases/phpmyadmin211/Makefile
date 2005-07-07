# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin
PORTVERSION=	2.6.3.1
#DISTVERSION=	2.6.3-pl1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpmyadmin
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/-pl\1/}

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to manage MySQL over the web

USE_BZIP2=	yes
NO_BUILD=	yes
USE_PHP=	mysql pcre

SUB_LIST+=	"MYADMDIR=${MYADMDIR}" \
		"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

# Unfortunately can't make WITH_SUPHP part of the OPTIONS selection,
# since it has to be processed before just about anything else.

.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)

PKGNAMESUFFIX=	-suphp
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes
PKGINST_SKEL=	${PKGDIR}/pkg-install${PKGNAMESUFFIX}
PKGINSTALL=	${WRKDIR}/pkg-install${PKGNAMESUFFIX}
PKGDEINST_SKEL=	${PKGDIR}/pkg-deinstall${PKGNAMESUFFIX}
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall${PKGNAMESUFFIX}

MYADMUSR?=	phpmyadm

SUB_LIST+=	"MYADMUSR=${MYADMUSR}" \
		"MYADMGRP=${MYADMGRP}"
SUB_FILES+=	pkg-install pkg-deinstall

.else

WANT_PHP_WEB=	yes

.endif

# Copy the way lang/php{4,5}-extensions deals with its OPTIONS -- avoids
# problems with include of bsd.port.pre.mk

OPTIONS=	BZ2	 "bzip2 library support" on \
		GD	 "GD library support" on \
		MYSQLI	 "Improved MySQL support (PHP5, MySQL 4.1 only)" off \
		OPENSSL	 "OpenSSL support" on \
		PDF	 "PDFlib support (implies GD)" on \
		ZLIB	 "ZLIB support" on \
		MCRYPT   "MCrypt library support" on \
		MBSTRING "Multi-byte character-set string support" on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

# Options that default to on:
.for opt in BZ2 GD OPENSSL PDF ZLIB MCRYPT MBSTRING
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

# MYADMUSR is only used WITH_SUPHP
MYADMDIR?=	www/phpMyAdmin
MYADMGRP?=	${WWWGRP}
CFGFILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	MYADMDIR=${MYADMDIR} MYADMGRP=${MYADMGRP}

.SILENT:

do-build:
	@${DO_NADA}

pre-everything::
	${ECHO_MSG} ""
	${ECHO_MSG} "You may use the following additional build option:"
	${ECHO_MSG} ""
	${ECHO_MSG} "    WITH_SUPHP=yes   Install appropriately for use with"
	${ECHO_MSG} "                     the www/suphp port [default: no]"
	${ECHO_MSG} ""

post-patch:
	${MV} ${WRKSRC}/${CFGFILE} ${WRKSRC}/${CFGFILE}.sample
	cd ${WRKSRC} ; \
	${FIND} . ! -type d ! -name ${CFGFILE}.sample | ${SORT} | \
	    ${SED} -e "s,^\.,%%MYADMDIR%%,"           >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk             >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
	     -e "s,^\.$$,@unexec rmdir %D/%%MYADMDIR%% 2>/dev/null || true," \
	     -e "s,^\.,@dirrm %%MYADMDIR%%,"         >>${PLIST}

pre-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore ) ; do \
	    dst=${PREFIX}/${MYADMDIR}$${src#.} ; \
	    if ${TEST} -d $$src ; then \
	        ${MKDIR} $$dst ; \
	    else \
	        ${INSTALL_DATA} $$src $$dst ; \
	    fi \
	done

install-conf: install-app
	cd ${PREFIX}/${MYADMDIR} ; \
	${CHMOD} 0640 ${CFGFILE}.sample ; \
	${CHGRP} ${MYADMGRP} ${CFGFILE}.sample ; \
	if ${TEST} ! -f ${CFGFILE} ; then \
	    ${CP} -p ${CFGFILE}.sample ${CFGFILE} ; \
	fi

post-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
