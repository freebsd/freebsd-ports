# New ports collection makefile for:	flyspray
# Date created:			2003.08.28
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	flyspray
PORTVERSION=	0.9.7
CATEGORIES=	devel
MASTER_SITES=	http://flyspray.rocks.cc/files/

MAINTAINER=	nick@foobar.org
COMMENT=	A simple, easy-to-use web based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/share/adodb/adodb.inc.php:${PORTSDIR}/databases/adodb

USE_REINPLACE=	yes
USE_PHP=	mysql pcre session
WANT_PHP_WEB=	yes

NO_BUILD=	yes

DBDIR=		/var/db

DOC_FILES=	AUTHORS.txt BUGS.txt CHANGELOG.txt INSTALL.txt README.txt \
		TODO.txt UPGRADING.txt README.FreeBSD \
		licences/ADOdb.licence.txt \
		licences/Flyspray.licence.txt \
		licences/NuvolaIcons.licence.txt \
		licences/jsCalendar.licence.txt \
		licences/phpMarkdown.licence.txt

FLYSPRAY_FILES=	favicon.ico header.php includes index.php lang scripts sql themes

PKGMESSAGE=	${WRKSRC}/pkg-message

post-patch:
	@${CP} ${PKGDIR}/files/README.FreeBSD ${WRKSRC}/docs/
	@${REINPLACE_CMD} -e "s|realpath('../')|'${PREFIX}/share'|g" \
		${WRKSRC}/sql/install-${PORTVERSION}.php
	@${RM} ${WRKSRC}/sql/install-${PORTVERSION}.php.bak

do-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	${CHMOD} 755 ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/header.php ${PREFIX}/share/${PORTNAME}/header.php-dist
	cd ${WRKSRC} && \
		tar cf - ${FLYSPRAY_FILES} | \
		(cd ${PREFIX}/share/${PORTNAME} && tar -xf -)
	${LN} -s ${DBDIR}/${PORTNAME}/attachments ${PREFIX}/share/${PORTNAME}/attachments
	@${MKDIR} ${DBDIR}/${PORTNAME}/attachments
	${CHMOD} 750 ${DBDIR}/${PORTNAME}/attachments
	${CHOWN} ${WWWOWN}:${WWWGRP} ${DBDIR}/${PORTNAME}/attachments
	${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/share/${PORTNAME}

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
