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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JCE (Java Cryptograph Extension) by Cryptix

USE_JAVA=	yes
USE_ZIP=	yes
NO_BUILD=	yes
RESTRICTED=	Testing purpose only (from README.TXT).

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-api.jar ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-compat.jar ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-provider.jar ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-tests.jar ${JAVAJARDIR}/

.include <bsd.port.mk>
