# Ports collection makefile for:  pear-HTML_Common
# Date created:			  29 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Common
PORTVERSION=	1.0
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

LPHP_LIB=	lib/php
PEARDIR=	${LOCALBASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

do-install:
	@${MKDIR} ${PEARDIR}/HTML
	@${CP} -Rp ${WRKSRC}/Common.php ${PEARDIR}/HTML
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML

.include <bsd.port.mk>
