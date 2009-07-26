# New ports collection makefile for:	squeezecenter-superdatetime
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	superdatetime
PORTVERSION=	5.8.7
CATEGORIES=	audio
MASTER_SITES=	http://www.gregbrown.net/squeeze/SuperDateTime/
PKGNAMEPREFIX=	squeezecenter-
DISTNAME=	SuperDateTime${PORTVERSION:S/./-/g}
DIST_SUBDIR=	squeezecenter

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SqueezeCenter plugin to display weather conditions and forecasts

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezecenter

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezecenter
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime
	${CP} -R ${WRKSRC}/SuperDateTime/* ${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime

.include <bsd.port.mk>
