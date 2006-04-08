# New ports collection makefile for:	vdrift-data
# Date created:		2006-02-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	20060221
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vdrift
PKGNAMEPREFIX=	vdrift-
DISTNAME=	${PKGNAMEPREFIX}2006-02-21-${PORTNAME}
DIST_SUBDIR=	vdrift

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Vdrift driving simulation data files

USE_ZIP=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/vdrift
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}2006-02-21

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && \
		${FIND} * -name SConscript -print0 | ${XARGS} -0 ${RM} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
