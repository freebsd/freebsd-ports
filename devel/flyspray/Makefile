# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	flyspray
PORTVERSION=	0.9.9.7
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://flyspray.org/

MAINTAINER=	nick@foobar.org
COMMENT=	Simple, easy-to-use web based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/share/adodb/adodb.inc.php:${PORTSDIR}/databases/adodb

USE_PHP=	pcre session zlib xml gd
USES=		dos2unix zip
WANT_PHP_WEB=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DOS2UNIX_REGEX=	.php

OPTIONS_DEFINE=	GRAPHVIZ MYSQL MYSQLI POSTGRES
OPTIONS_DEFAULT=	MYSQLI

MYSQLI_DESC=	Use MySQLi Database Interface
POSTGRES_DESC=	Use PostgreSQL Database Interface

FLYSPRAYDIR=	${PREFIX}/share/${PORTNAME}
ATTACHMENTDIR=	${DBDIR}/${PORTNAME}/attachments
DBDIR=		/var/db

DOC_FILES=	AUTHORS.txt BUGS.txt CHANGELOG.txt INSTALL.txt \
		QA_CHECKLIST.txt README.txt TODO.txt UPGRADING.txt \
		README.FreeBSD \
		licences/ADOdb.licence.txt \
		licences/Flyspray.licence.txt \
		licences/NuvolaIcons.licence.txt \
		licences/jsCalendar.licence.txt

FLYSPRAY_FILES=	cache docs/licences/gnu_lgpl.html favicon.ico \
		flyspray.conf.php-dist feed.php header.php htaccess.dist \
		includes index.php javascript lang plugins robots.txt \
		schedule.php scripts setup templates themes

SUB_FILES+=	pkg-message pkg-install
SUB_LIST+=	FLYSPRAYDIR="${FLYSPRAYDIR}" \
		ATTACHMENTDIR="${ATTACHMENTDIR}" \
		MKDIR="${MKDIR}" \
		CHOWN="${CHOWN}" \
		CHMOD="${CHMOD}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MPOSTGRES}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
.endif

post-patch:
	@${CP} ${PKGDIR}/files/README.FreeBSD ${WRKSRC}/docs/
	@${REINPLACE_CMD} -e "s|%%FLYSPRAYDIR%%|"${FLYSPRAYDIR}"|g" \
		-e "s|%%DOCSDIR%%|"${DOCSDIR}"|g" \
		${WRKSRC}/docs/README.FreeBSD
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} '{}' ';'
	@${REINPLACE_CMD} "s|E_ALL|E_ALL \& ~E_STRICT|g" \
		${WRKSRC}/includes/fix.inc.php
	@${RM} ${WRKSRC}/includes/fix.inc.php.bak

do-install:
	${MKDIR} ${FLYSPRAYDIR}
	${CHMOD} 755 ${FLYSPRAYDIR}
	${CP} ${WRKSRC}/setup/upgrade/${PORTVERSION}/flyspray.conf.php ${WRKSRC}/flyspray.conf.php-dist
	${TOUCH} ${FLYSPRAYDIR}/flyspray.conf.php
	cd ${WRKSRC} && \
		${TAR} cf - ${FLYSPRAY_FILES} | \
		(cd ${FLYSPRAYDIR} && ${TAR} -xf -)
	${LN} -s ${ATTACHMENTDIR} ${FLYSPRAYDIR}/attachments
	${LN} -s ${PREFIX}/share/adodb ${FLYSPRAYDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${FLYSPRAYDIR}/cache ${FLYSPRAYDIR}/flyspray.conf.php
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-install: install-doc
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
