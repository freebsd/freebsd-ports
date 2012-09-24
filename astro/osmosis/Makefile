# New ports collection makefile for:	osmosis
# Date created:		2009/09/21
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osmosis
PORTVERSION=	0.41
CATEGORIES=	astro java
MASTER_SITES=	http://bretth.dev.openstreetmap.org/osmosis-build/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line Java app for processing OpenStreetMap data

NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

post-patch:
	@${REINPLACE_CMD} -e 's|^\(MYAPP_HOME=\).*|\1${DATADIR}|' ${WRKSRC}/bin/osmosis

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "script config lib" ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/osmosis ${PREFIX}/bin/

.include <bsd.port.mk>
