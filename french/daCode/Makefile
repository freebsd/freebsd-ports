# New ports collection makefile for:   daCode-1.2.0
# Date created:        4 September 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	daCode
PORTVERSION=	1.2.0
CATEGORIES=	french
MASTER_SITES=	http://switch.dl.sourceforge.net/sourceforge/dacode/

MAINTAINER=	gioria@FreeBSD.org

RUN_DEPENDS+= 	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/lang/php3

NO_BUILD=	yes

do-install:
	${ECHO} "Installing in ${PREFIX}/www/dadode"
	${MKDIR} ${PREFIX}/www/dacode
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/dacode
	${CHOWN} -R www:www ${PREFIX}/www/dacode

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
