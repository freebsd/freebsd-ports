# New ports collection makefile for:	Java Cryptograph Extension by Cryptix
# Date created:		2000/02/19
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	cryptix-jce
PORTVERSION=	20011118
CATEGORIES=	java security
MASTER_SITES=	http://opensores.thebunker.net/pub/mirrors/cryptix/dist/ \
		http://www.mirrors.wiretapped.net/security/cryptography/libraries/cryptix/cryptix-jce/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	${PORTNAME}-${PORTVERSION}-snap

MAINTAINER=	znerd@FreeBSD.org

USE_JAVA=	1.1+
USE_ZIP=	yes
NO_BUILD=	yes
RESTRICTED=	Testing purpose only (from README.TXT).

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-api.jar ${PREFIX}/share/java/classes/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-compat.jar ${PREFIX}/share/java/classes/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-provider.jar ${PREFIX}/share/java/classes/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-tests.jar ${PREFIX}/share/java/classes/

.include <bsd.port.mk>
