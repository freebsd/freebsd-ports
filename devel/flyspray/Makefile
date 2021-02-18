# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	flyspray
PORTVERSION=	0.9.9.7
PORTREVISION=	4
CATEGORIES=	devel www
MASTER_SITES=	http://flyspray.org/packed/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, easy-to-use web based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/share/adodb/adodb.inc.php:databases/adodb5

USE_PHP=	pcre session zlib xml gd
USES=		dos2unix php:web zip

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

DOS2UNIX_REGEX=	.php

OPTIONS_DEFINE=	GRAPHVIZ MYSQLI PGSQL DOCS
OPTIONS_DEFAULT=	MYSQLI

DOCS_SUB_FILES=	pkg-message

MYSQLI_DESC=	Use MySQLi Database Interface

FLYSPRAYDIR=	${PREFIX}/share/${PORTNAME}
FSINSTALLDIR=	${STAGEDIR}${FLYSPRAYDIR}
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

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

MYSQLI_USE=	PHP=mysqli
PGSQL_USE=	PHP=pgsql
GRAPHVIZ_RUN_DEPENDS=	${LOCALBASE}/bin/dot:graphics/graphviz

post-patch:
	@${CP} ${PKGDIR}/files/README.FreeBSD ${WRKSRC}/docs/
	@${REINPLACE_CMD} -e "s|%%FLYSPRAYDIR%%|"${FLYSPRAYDIR}"|g" \
		-e "s|%%DOCSDIR%%|"${DOCSDIR}"|g" \
		${WRKSRC}/docs/README.FreeBSD
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} {} ';'
	@${REINPLACE_CMD} "s|E_ALL|E_ALL \& ~E_STRICT|g" \
		${WRKSRC}/includes/fix.inc.php
	@${RM} ${WRKSRC}/includes/fix.inc.php.bak

do-install:
	${MKDIR} ${FSINSTALLDIR}
	${CP} ${WRKSRC}/setup/upgrade/${PORTVERSION}/flyspray.conf.php ${WRKSRC}/flyspray.conf.php-dist
	${TOUCH} ${FSINSTALLDIR}/flyspray.conf.php
	cd ${WRKSRC} && \
		${TAR} cf - ${FLYSPRAY_FILES} | \
		(cd ${FSINSTALLDIR} && ${TAR} -xf -)
	${LN} -sf ${ATTACHMENTDIR} ${FSINSTALLDIR}/attachments
	${LN} -sf ${PREFIX}/share/adodb ${FSINSTALLDIR}
	${MKDIR} ${STAGEDIR}${ATTACHMENTDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
