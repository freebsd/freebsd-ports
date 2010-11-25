# New ports collection makefile for:	openarena-oax
# Date created:				21 May 2010
# Whom:					Dominic Fandrey
#
# $FreeBSD$
#

PORTNAME=	oax
PORTVERSION=	B45
CATEGORIES=	games
MASTER_SITES=	http://files.poulsander.com/~poul19/public_files/eliminationSource/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.zip
EXTRACT_ONLY=

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	OpenArena Mod: OpenArena Xpanded

USE_ZIP=	yes

PLIST_SUB+=	DISTNAME="${DISTNAME}" \
		PORTNAME="${PORTNAME}"

NO_BUILD=	yes

OABASE=		${DISTNAME}

do-install:
	@${MKDIR} ${DATADIR}
	@${UNZIP_CMD} ${DISTDIR}/${DISTFILES} -d ${OADIR}
	@${CHMOD} -R o-w ${DATADIR}

.include "../openarena/Makefile.include"
