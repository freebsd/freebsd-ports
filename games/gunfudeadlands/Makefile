# New ports collection makefile for:	gunfudeadlands
# Date created:		21 Dec 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gunfudeadlands
PORTVERSION=	1.01
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/GunFu%20Deadlands%20${PORTVERSION}/
DISTNAME=	GunFuDeadlands_${PORTVERSION:C/\.//}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Far West themed 2D shooter featuring bullet time

RUN_DEPENDS=	love:${PORTSDIR}/devel/love

USE_ZIP=	yes
NO_BUILD=	yes

SUB_FILES=	gunfudeadlands

PLIST_FILES=	bin/gunfudeadlands \
		%%DATADIR%%/GunFuDeadlands.zip
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	*

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DATADIR}/GunFuDeadlands.zip
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
