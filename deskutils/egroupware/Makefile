# New ports collection makefile for:	egroupware
# Date created:        27 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	eGroupWare
PORTVERSION=	1.4.004
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	wenheping@gmail.com
COMMENT=	A web based GroupWare system

USE_BZIP2=	yes
NO_BUILD=	yes
#WRKSRC=		${DEST}

DEST=		${PREFIX}/www/data-dist/egroupware

OPTIONS=	MYSQL "Use MySQL database" on \
		POSTGRE "Use PostgreSQL Database" off \
		IMAP "Enable Mail support in eGroupware" on \
		GD "Enable graphic support (needs xorg-libraries)" off \
		PEAR "Req. by SyncML (see pkg-msg for php.ini)" on \
		LDAP "Contacts can be stored using OpenLDAP" off
#	doesn't work!	MBSTRING "Support for complete UTF-8 charsets" off

.include <bsd.port.pre.mk>

USE_PHP=	pcre session xml

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif
.if defined(WITH_POSTGRE)
USE_PHP+=	pgsql
.endif
.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif
.if defined(WITH_IMAP)
USE_PHP+=	imap
.endif
.if defined(WITH_GD)
USE_PHP+=	gd
.endif
.if defined(WITH_PEAR)
RUN_DEPENDS=	${LOCALBASE}/share/pear/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif
.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.include "${PORTSDIR}/Mk/bsd.php.mk"

do-extract:
	${MKDIR} ${WRKDIR}

do-install:
	${MKDIR} ${DEST}
	cd ${DEST}/.. && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS}
	@${FIND} ${DEST} -name .svn -type d | ${XARGS} ${RM} -rf
	${MKDIR} /var/db/egroupware/default
	${MKDIR} /var/db/egroupware/default/files
	${MKDIR} /var/db/egroupware/default/backup
	${MKDIR} /var/db/egroupware/default/sessions
	${CHMOD} g+w ${DEST} ${DEST}/phpgwapi/images
	${CHMOD} -R g+w /var/db/egroupware
	${CHGRP} ${WWWGRP} ${DEST} ${DEST}/phpgwapi/images
	${CHGRP} -R ${WWWGRP} /var/db/egroupware
	${MV} ${DEST}/setup/inc/class.setup_process.inc.php ${WRKDIR}
	${SED} s,/var/lib/,/var/db/, ${WRKDIR}/class.setup_process.inc.php > \
		${DEST}/setup/inc/class.setup_process.inc.php

# --- postgresql.conf
# tcpip_socket = true
# ports = 5432
#
# --- pg_hba.conf
# local $dbname trust
# host  $dbname all   127.0.0.1 255.255.255.255 md5
#
# --- php.ini
# memory_limit = 16M (or above)
#
# createuser $dbuser -P -A -d
# createdb -U $dbuser $dbname
#
# Open http://localhost/egroupware/setup/index.php

.include <bsd.port.post.mk>
