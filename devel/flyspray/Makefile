# New ports collection makefile for:	flyspray
# Date created:			2003.08.28
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	flyspray
PORTVERSION=	0.9.5
CATEGORIES=	devel
MASTER_SITES=	http://flyspray.rocks.cc/files/

MAINTAINER=	nick@foobar.org
COMMENT=	A simple, easy-to-use web based bug tracking system

RUN_DEPENDS=	${LOCALBASE}/share/adodb/adodb.inc.php:${PORTSDIR}/databases/adodb

USE_PHP=	mysql pcre session
WANT_PHP_WEB=	yes

NO_BUILD=	yes

DBDIR=		/var/db

DOC_FILES=	AUTHORS BUGS CHANGELOG COPYING INSTALL README TODO UPGRADING sql/flyspray-${PORTVERSION}.mysql
FLYSPRAY_FILES=	favicon.ico functions.inc.php functions.js index.php lang scripts themes regexp.php sql/upgrade_0.9.4_to_0.9.5-mysql.php

do-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${CHMOD} 755 ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/header.php ${PREFIX}/share/${PORTNAME}/header.php-dist
	cd ${WRKSRC} && \
		tar cf - ${FLYSPRAY_FILES} | \
		(cd ${PREFIX}/share/${PORTNAME} && tar -xf -)
	${LN} -s ${DBDIR}/${PORTNAME}/attachments ${PREFIX}/share/${PORTNAME}/attachments
	${MKDIR} ${DBDIR}/${PORTNAME}/attachments
	${CHMOD} 750 ${DBDIR}/${PORTNAME}/attachments
	${CHOWN} www:www ${DBDIR}/${PORTNAME}/attachments

post-install: install-doc
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
