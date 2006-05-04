# New ports collection makefile for:	flyspray
# Date created:			2003.08.28
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	flyspray
PORTVERSION=	0.9.8
CATEGORIES=	devel
MASTER_SITES=	http://flyspray.rocks.cc/files/

MAINTAINER=	nick@foobar.org
COMMENT=	A simple, easy-to-use web based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/share/adodb/adodb.inc.php:${PORTSDIR}/databases/adodb

USE_PHP=	mysql pcre session
WANT_PHP_WEB=	yes

NO_BUILD=	yes

FLYSPRAYDIR=	${PREFIX}/share/${PORTNAME}
ATTACHMENTDIR=	${DBDIR}/${PORTNAME}/attachments
DBDIR=		/var/db

DOC_FILES=	AUTHORS.txt BUGS.txt CHANGELOG.txt INSTALL.txt \
		QA_CHECKLIST.txt README.txt TODO.txt UPGRADING.txt \
		README.FreeBSD \
		licences/ADOdb.licence.txt \
		licences/Flyspray.licence.txt \
		licences/NuvolaIcons.licence.txt \
		licences/class.jabber.php.licence.txt \
		licences/jsCalendar.licence.txt \
		licences/phpMarkdown.licence.txt \
		licences/phpmailer.licence.txt \

FLYSPRAY_FILES=	.htaccess favicon.ico header.php index.php \
		remote-client.php remote.php docs/licences/gnu_lgpl.html \
		includes lang scripts setup sql themes

PKGMESSAGE=	${WRKSRC}/pkg-message

post-patch:
	@${CP} ${PKGDIR}/files/README.FreeBSD ${WRKSRC}/docs/
	@${REINPLACE_CMD} -e "s|%%FLYSPRAYDIR%%|"${FLYSPRAYDIR}"|g" \
		-e "s|%%DOCSDIR%%|"${DOCSDIR}"|g" \
		${WRKSRC}/docs/README.FreeBSD
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} '{}' ';'

do-install:
	@${MKDIR} ${FLYSPRAYDIR}
	${CHMOD} 755 ${FLYSPRAYDIR}
	${INSTALL_DATA} ${WRKSRC}/flyspray.conf.php \
		${FLYSPRAYDIR}/flyspray.conf.php-dist
	${TOUCH} ${FLYSPRAYDIR}/flyspray.conf.php
	cd ${WRKSRC} && \
		tar cf - ${FLYSPRAY_FILES} | \
		(cd ${FLYSPRAYDIR} && tar -xf -)
	${LN} -s ${ATTACHMENTDIR} ${FLYSPRAYDIR}/attachments
	${LN} -s ${PREFIX}/share/adodb ${FLYSPRAYDIR}
	@${MKDIR} ${ATTACHMENTDIR}
	${CHMOD} 750 ${ATTACHMENTDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${ATTACHMENTDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${FLYSPRAYDIR}/flyspray.conf.php

post-install: install-doc
	@${SED} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
