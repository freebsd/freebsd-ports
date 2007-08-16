# New ports collection makefile for:	flyspray
# Date created:			2003.08.28
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	flyspray
PORTVERSION=	0.9.9.2
CATEGORIES=	devel
MASTER_SITES=	http://www.flyspray.org/

MAINTAINER=	nick@foobar.org
COMMENT=	A simple, easy-to-use web based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/share/adodb/adodb.inc.php:${PORTSDIR}/databases/adodb

USE_PHP=	mysql pcre session zlib xml gd
USE_BZIP2=	yes
WANT_PHP_WEB=	yes

NO_BUILD=	yes

OPTIONS=	GRAPHVIZ "Install Graphviz for task dependency graphs" off

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

FLYSPRAY_FILES=	cache docs/licences/gnu_lgpl.html \
		favicon.ico feed.php header.php htaccess.dist includes \
		index.php javascript lang plugins robots.txt schedule.php \
		scripts setup templates themes

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

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
	@${MKDIR} ${FLYSPRAYDIR}
	${CHMOD} 755 ${FLYSPRAYDIR}
	${TOUCH} ${FLYSPRAYDIR}/flyspray.conf.php
	cd ${WRKSRC} && \
		${TAR} cf - ${FLYSPRAY_FILES} | \
		(cd ${FLYSPRAYDIR} && ${TAR} -xf -)
	${LN} -s ${ATTACHMENTDIR} ${FLYSPRAYDIR}/attachments
	${LN} -s ${PREFIX}/share/adodb ${FLYSPRAYDIR}
	@${MKDIR} ${ATTACHMENTDIR}
	${CHMOD} 750 ${ATTACHMENTDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${ATTACHMENTDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${FLYSPRAYDIR}/cache
	${CHOWN} ${WWWOWN}:${WWWGRP} ${FLYSPRAYDIR}/flyspray.conf.php

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
