# New ports collection makefile for:	flyspray
# Date created:			2003.08.28
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	flyspray
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://flyspray.rocks.cc/

MAINTAINER=	nick@foobar.org
COMMENT=	A simple, easy-to-use web based bug tracking system

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

NO_BUILD=       yes
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

DOC_FILES=	AUTHORS BUGS CHANGELOG COPYING INSTALL README TODO UPGRADING flyspray-${PORTVERSION}.sql

do-fetch: ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${MASTER_SITES}/?file=${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${CHMOD} 755 ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config.inc.php ${PREFIX}/share/${PORTNAME}/config.inc.php-dist
	cd ${WRKSRC} && \
		tar cf - favicon.ico functions.inc.php functions.js header.php index.php lang scripts themes | \
		(cd ${PREFIX}/share/${PORTNAME} && tar -xf -)
	${LN} -s /var/db/${PORTNAME}/attachments ${PREFIX}/share/${PORTNAME}/attachments
	${MKDIR} /var/db/${PORTNAME}/attachments
	${CHMOD} 750 /var/db/${PORTNAME}/attachments
	${CHOWN} www:www /var/db/${PORTNAME}/attachments

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
