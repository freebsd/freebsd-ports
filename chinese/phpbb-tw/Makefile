# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	phpbb
PORTVERSION=	2.0.23
CATEGORIES=	chinese www
MASTER_SITES=	LOCAL/chinsan/php/ \
		http://freebsd.ee.ccu.edu.tw/
PKGNAMESUFFIX=	-tw
DISTNAME=	phpBB-tw-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Traditional Chinese version of phpBB

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:devel/pear

CONFLICTS=	phpbb-[0-9]*
USES=		dos2unix

# Get HOSTNAME
.if exists(/sbin/sysctl)
HOSTNAME!=	/sbin/sysctl -n kern.hostname
.else
HOSTNAME!=	/usr/sbin/sysctl -n kern.hostname
.endif

# The phpBB2 port supports a number of variables that may be tweaked at build
# time.  Perform a "make options" to see more information on these variables.
#
WWWDOCROOT?=	www
PHPBB_URL?=	phpBB2
#
# End of user-configurable variables.

# Set/override/append to variables from bsd.port.mk:
#
WRKSRC=		${WRKDIR}/phpBB2
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBB_URL="${PHPBB_URL}" \
		PHPBBDIR="${PHPBBDIR}" \
		HOSTNAME="${HOSTNAME}" \
		DELETEFILES="${EXCEPTFILES}"
PHPBB_VER=	${PORTVERSION:S/.//g:S/.//g}
PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PLIST_SUB+=	PHPBB_VER=${PHPBB_VER}

# Set custom variables:
#
PHPBBDIR=	${WWWDOCROOT}/${PHPBB_URL}
PKGOPTS=	${FILESDIR}/pkg-opts
EXCEPTFILES=	${STAGEDIR}${PREFIX}/${PHPBBDIR}/install/install.php \
		${STAGEDIR}${PREFIX}/${PHPBBDIR}/install/upgrade.php \
		${STAGEDIR}${PREFIX}/${PHPBBDIR}/install/update_to_latest.php

OPTIONS_DEFINE=	DOCS

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

pre-everything::
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

post-patch:
	@ ${REINPLACE_CMD} -e "s#\.\./templates#/${PHPBB_URL}/templates#" \
	  ${WRKSRC}/docs/*.html
	@${RM} -f `${FIND} ${WRKSRC} -name '*.orig'`

do-install:
	@ ${MKDIR} -m 0775 ${STAGEDIR}${PREFIX}/${PHPBBDIR}
	@ cd ${WRKSRC} && ${FIND} * \( -name config.php \
	  ${EXCEPTFILES:S/^/-o -name /} \
	  -o -name docs -a -prune -o -name contrib -a -prune \) -o -print \
	  | ${TAR} cTf - - | ${TAR} xUCf ${STAGEDIR}${PREFIX}/${PHPBBDIR} -
	@ ${TOUCH} ${STAGEDIR}${PREFIX}/${PHPBBDIR}/config.php
	@ ${MKDIR} ${STAGEDIR}${DATADIR}/contrib
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${EXCEPTFILES} ${STAGEDIR}${DATADIR}
	@ cd ${WRKSRC}/contrib && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}/contrib

post-install:
#	@ cd ${DATADIR} && ${INSTALL} -c -o ${WWWOWN} -g ${WWWGRP} \
#	  ${EXCEPTFILES} ${PREFIX}/${PHPBBDIR}
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
	@ cd ${WRKSRC}/docs && ${FIND} * -type f -maxdepth 0 \! -name \*.bak \
	  \! -name COPYING -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;

.include <bsd.port.mk>
