# New ports collection makefile for:   SPIP-1.4
# Date created:        3 September 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	SPIP
PORTVERSION=	1.5
CATEGORIES=	french
MASTER_SITES=	http://rezo.net/spip-dev/devel/
DISTNAME= 	SPIP-v1-5
EXTRACT_SUFX=	.tgz

MAINTAINER=	gioria@FreeBSD.org

BUILD_DEPENDS= 	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/lang/php3

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${ECHO} "Installing in ${PREFIX}/www/SPIP"
	${MKDIR} ${PREFIX}/www/SPIP
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/SPIP
	${CHOWN} -R www:www ${PREFIX}/www/SPIP

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
