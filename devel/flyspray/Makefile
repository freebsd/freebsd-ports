# New ports collection makefile for:	flyspray
# Date created:			2003.08.28
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	flyspray
PORTVERSION=	0.9.9.6
CATEGORIES=	devel www
MASTER_SITES=	http://flyspray.org/

MAINTAINER=	nick@foobar.org
COMMENT=	A simple, easy-to-use web based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/share/adodb/adodb.inc.php:${PORTSDIR}/databases/adodb

USE_PHP=	pcre session zlib xml gd
USE_ZIP=	yes
WANT_PHP_WEB=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	GRAPHVIZ "Install Graphviz for task dependency graphs" off \
		MYSQLI "Use MySQLi Database Interface" on \
		MYSQL "Use MySQL Database Interface" off

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

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if !defined(WITHOUT_MYSQLI)
USE_PHP+=	mysqli
.endif

.ifdef WITH_GRAPHVIZ
RUN_DEPENDS+=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
.endif

post-patch:
	@${CP} ${PKGDIR}/files/README.FreeBSD ${WRKSRC}/docs/
	@${REINPLACE_CMD} -e "s|%%FLYSPRAYDIR%%|"${FLYSPRAYDIR}"|g" \
		-e "s|%%DOCSDIR%%|"${DOCSDIR}"|g" \
		${WRKSRC}/docs/README.FreeBSD
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} '{}' ';'

do-install:
	${MKDIR} ${FLYSPRAYDIR}
	${CHMOD} 755 ${FLYSPRAYDIR}
	${CP} ${WRKSRC}/setup/upgrade/0.9.9.5/flyspray.conf.php ${WRKSRC}/flyspray.conf.php-dist
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

.include <bsd.port.post.mk>
