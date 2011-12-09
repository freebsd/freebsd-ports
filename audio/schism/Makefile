# New ports collection makefile for:	Schism Tracker
# Date created:				26 May 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	schism
PORTVERSION=	20100101
CATEGORIES=	audio
MASTER_SITES=	http://schismtracker.org/dl/ \
		CRITICAL
DISTNAME=	schismtracker-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A module tracker editor/player resembling impulse tracker

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64

USE_SDL=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}

# this version segfaults
PORTSCOUT=	skipv:20110101

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/schismtracker ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900027
EXTRA_PATCHES=	${FILESDIR}/extrapatch-modplug__snd_gm.c
.endif

.include <bsd.port.post.mk>
