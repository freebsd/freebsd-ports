# New ports collection makefile for:	slimserver-superdatetime
# Date created:		22 January 2007
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	superdatetime
PORTVERSION=	5.0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.gregbrown.net/squeeze/SuperDateTime/
PKGNAMEPREFIX=	slimserver-
DISTNAME=	SuperDateTime${PORTVERSION:S/./-/g}
DIST_SUBDIR=	slimserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SlimServer plugin to display current weather conditions and forecasts

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/slimserver

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime
	${INSTALL_DATA} ${WRKSRC}/SuperDateTime/* ${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime

.include <bsd.port.mk>
