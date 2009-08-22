# New ports collection makefile for:	slimserver-slimscrobbler
# Date created:				2005-12-31
# Whom:					freebsd-ports@varju.ca
#
# $FreeBSD$

PORTNAME=	slimscrobbler
PORTVERSION=	0.37.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/V0.37
PKGNAMEPREFIX=	slimserver-
DISTNAME=	SlimScrobbler${DISTVERSION:S/.//g}

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	SlimServer plugin for submitting updates to last.fm

RUN_DEPENDS=	${LOCALBASE}/bin/softsqueeze:${PORTSDIR}/audio/slimserver

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
CPIOARGS=	--quiet -pdum -R

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	@cd ${WRKDIR} && \
	    ${FIND} *Scrobble* | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${PREFIX}/${SLIMDIR}/Plugins

.include <bsd.port.mk>
