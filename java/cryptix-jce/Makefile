# New ports collection makefile for:	Java Cryptograph Extension by Cryptix
# Date created:		2000/02/19
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	cryptix-jce
PORTVERSION=	20000211
CATEGORIES=	java security
MASTER_SITES=	http://cvs.cryptix.org/~gelderen/

MAINTAINER=	greg@greg.rim.or.jp

RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk

USE_ZIP=	yes
NO_BUILD=	yes
RESTRICTED=	Testing purpose only (from README.TXT).

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	${INSTALL_DATA} ${WRKDIR}/bin/cryptix-jce-api.jar ${PREFIX}/share/java/classes/
	${INSTALL_DATA} ${WRKDIR}/bin/cryptix-jce-compat.jar ${PREFIX}/share/java/classes/
	${INSTALL_DATA} ${WRKDIR}/bin/cryptix-jce-provider.jar ${PREFIX}/share/java/classes/
	${INSTALL_DATA} ${WRKDIR}/bin/cryptix-jce-tests.jar ${PREFIX}/share/java/classes/

.include <bsd.port.mk>
