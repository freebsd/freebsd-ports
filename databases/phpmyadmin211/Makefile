# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin
PORTVERSION=	2.5.7.1
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpmyadmin
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/-pl\1/}

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to administer MySQL over the web

USE_BZIP2=	yes
NO_BUILD=	yes
USE_PHP=	bz2 gd mysql openssl pcre pdf zlib

.if defined(WITH_SUPHP)

PKGNAMESUFFIX=	-suphp
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes
PKGINST_SKEL=	${PKGDIR}/pkg-install${PKGNAMESUFFIX}
PKGINSTALL=	${WRKDIR}/pkg-install${PKGNAMESUFFIX}
PKGDEINST_SKEL=	${PKGDIR}/pkg-deinstall${PKGNAMESUFFIX}
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall${PKGNAMESUFFIX}

MYADMUSR?=	phpmyadm

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g'     \
		-e 's,%%MYADMDIR%%,${MYADMDIR},g' \
		-e 's,%%MYADMUSR%%,${MYADMUSR},g' \
		-e 's,%%MYADMGRP%%,${MYADMGRP},g'

.else

WANT_PHP_WEB=	yes

.endif

MSG_SKEL=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# MYADMUSR is only used WITH_SUPHP
MYADMDIR?=	www/phpMyAdmin
MYADMGRP?=	${WWWGRP}
CFGFILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	MYADMDIR=${MYADMDIR} MYADMGRP=${MYADMGRP}

.SILENT:

pre-everything::
	${ECHO_MSG} ""
	${ECHO_MSG} "You may use the following build options:"
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
	${SED} -e 's,%%MYADMDIR%%,${MYADMDIR},g' \
	       -e 's,%%PREFIX%%,${PREFIX},g'     \
	       -e 's,%%PKGNAME%%,${PKGNAME},g' ${MSG_SKEL} > ${PKGMESSAGE}
.if defined(WITH_SUPHP)
	${SED} ${SED_SCRIPT} ${PKGINST_SKEL}   > ${PKGINSTALL}
	${SED} ${SED_SCRIPT} ${PKGDEINST_SKEL} > ${PKGDEINSTALL}
.endif

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
