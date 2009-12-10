# New ports collection makefile for:	squeezeboxserver-superdatetime
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	superdatetime
PORTVERSION=	5.8.9
CATEGORIES=	audio
MASTER_SITES=	http://www.gregbrown.net/squeeze/SuperDateTime/
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	SuperDateTime${PORTVERSION:S/./-/g}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin to display weather conditions and forecasts

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezeboxserver

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime
	${CP} -R ${WRKSRC}/SuperDateTime/* ${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime

.include <bsd.port.mk>
