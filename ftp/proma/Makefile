# $FreeBSD$

PORTNAME=	proma
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	Administrate a ProFTPd server storing users in a MySQL database

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		define an @exec depending on %F and %B before any files defined

USE_BZIP2=	yes
NO_BUILD=	yes

PORTDOCS=	ChangeLog INSTALL README TODO UPGRADE
FILES=		index.php style.css config.inc.php-example
LIBS=		admin.lib.php auth.lib.php common.lib.php
PAGES=		admin.inc.php change.inc.php main.inc.php register.inc.php

OPTIONS=	PROFTPD "Install ProFTPd with MySQL support" off \
		APACHE "Install Apache Web Server 2.2.x" off \
		MYSQL "Install MySQL Server 5.x" off \
		PHP "Install PHP5 with MySQL support" off

SUB_FILES=	pkg-message

.if defined(WITH_PROFTPD)
RUN_DEPENDS+=	${LOCALBASE}/libexec/proftpd/mod_sql_mysql.so:${PORTSDIR}/databases/proftpd-mod_sql_mysql
.endif
.if defined(WITH_APACHE)
USE_APACHE_RUN=	22
.endif
.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif
.if defined(WITH_PHP)
USE_PHP=    mysql pcre xml gd
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
	@${MKDIR} ${WWWDIR}/
	@${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/,} ${WWWDIR}/
	@${INSTALL} -d ${WWWDIR}/libs
	@${INSTALL_DATA} ${LIBS:S,^,${WRKSRC}/libs/,} ${WWWDIR}/libs/
	@${INSTALL} -d ${WWWDIR}/pages
	@${INSTALL_DATA} ${PAGES:S,^,${WRKSRC}/pages/,} ${WWWDIR}/pages/

post-install:
	@if [ ! -f ${WWWDIR}/config.inc.php ]; then \
		${CP} -p ${WRKSRC}/config.inc.php-example ${WWWDIR}/config.inc.php ; \
		${CP} -p ${WRKSRC}/config.inc.php-example ${WWWDIR}/config.inc.php-example ; \
		${CHMOD} 640 ${WWWDIR}/config.inc.php* ; \
	fi
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
